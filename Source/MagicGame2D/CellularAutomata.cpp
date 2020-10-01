// Fill out your copyright notice in the Description page of Project Settings.


#include "CellularAutomata.h"

#include <memory>
#include <xutility>

// Sets default values for this component's properties
UCellularAutomata::UCellularAutomata()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	fastNoise = FastNoise();
	fastNoise.SetSeed(1531263636);
	srand (time(NULL));
	// ...
}


// Called when the game starts
void UCellularAutomata::BeginPlay() {
	Super::BeginPlay();	
}

map<Vector2, int> UCellularAutomata::Smooth(map<Vector2, int> automata)
{
	map<Vector2, int> updated = map<Vector2, int>();

	for (int i = 0; i < Globals::SMOOTH_ITERATIONS; i++) {
		for (std::map<Vector2, int>::iterator iter = automata.begin(); iter != automata.end(); ++iter) {
			Vector2 pos = iter->first;
			int walls = GetNumberOfWalls(pos, automata);
			
			if (walls > Globals::SMOOTH_WALL_THRESHOLD) {
				updated[pos] = 1;
			}
			else {
				updated[pos] = 0;
			}

		}
		automata = updated;
	}


	return automata;
}

int UCellularAutomata::GetNumberOfWalls(Vector2 pos, map<Vector2, int> automata)
{
	int number = 0;
	for (int x = -1; x <= 1; x++) {
		for (int z = -1; z <= 1; z++) {
			if (x == 0 && z == 0) continue;
			Vector2 nPos = pos.add(Vector2(x * Globals::SQUARE_SIZE, z * Globals::SQUARE_SIZE));
			if (automata.count(nPos) <= 0) continue;
			int value = automata.at(nPos);
			if (value > 0) {
				number++;
			}
		}
	}
	return number;
}



// Called every frame
void UCellularAutomata::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCellularAutomata::Generate(GenerationData* data)
{
	UE_LOG(LogTemp, Warning, TEXT("Generate"));
	UE_LOG(LogTemp, Warning, TEXT("Values: %d"), Globals::SQUARE_SIZE);


	map<Vector2, float> cell = map<Vector2, float>();
	map<Vector2,int> cellular = map<Vector2,int>();
	int zero = 0;
	int one = 0;
	float min = FLT_MAX_EXP;
	float max = FLT_MIN_EXP;
	int i = 0;
	
	for (int x = 0; x < Globals::CHUNK_SIZE; x++) {
		for (int z = 0; z < Globals::CHUNK_SIZE; z++) {
			
			Vector2 pos = Vector2(data->getBoundingBox()->min.X + (x*Globals::SQUARE_SIZE),
								  data->getBoundingBox()->min.Z + (z* Globals::SQUARE_SIZE));
			float value = fastNoise.GetNoise(pos.X/10.f, pos.Z/10.f);
			value++;
			value /= 2;
			cell.emplace(pos,value);
			if(value < min) {
				min = value;
			}
			if(value > max) {
				max = value;
			}


		}
 	}
	float total = abs(min) + abs(max);
	std::map<int,FastNoise> noiseFunctions;
	for (auto material : (*data->GetBaseMaterials())) {
		noiseFunctions.emplace(material.second->Index,FastNoise(material.second->Index*13));
	} 
	for(auto &&values :cell) {
		i++;

		values.second += abs(min);
		values.second/=total;
		if(values.second > .45f) {
			int material = assignBaseMaterials(&noiseFunctions,data->GetBaseMaterials(),values.first);
			int ore = assignOres(data->GetOres(),values.first);
			if(ore != -1) material = ore;
			// UE_LOG(LogTemp, Warning, TEXT("material: %d"), material);

			cellular.emplace(values.first,material);
			
			one++;
			continue;
		}
		cellular.emplace(values.first,0);
		zero++;
	}
	UE_LOG(LogTemp, Warning, TEXT("Iterations: %d" ),cell.size());

	
	UE_LOG(LogTemp, Warning, TEXT("On: %d" ),one);
	UE_LOG(LogTemp, Warning, TEXT("Off: %d"),zero);
	UE_LOG(LogTemp, Warning, TEXT("Total: %d"),(zero+one));

	Smooth(cellular);

	data->setAutomata(make_shared<map<Vector2,int>>(cellular));
	UE_LOG(LogTemp, Warning, TEXT("Total Automata: %d"),(data->getAutomata()->size()));

}

int UCellularAutomata::assignBaseMaterials(std::map<int,FastNoise>* noiseFunction,
										   shared_ptr<std::map<int,FMaterialDataTableStruct*>> baseMaterials,
										   Vector2 position) {
	vector<int> materials;
	for(auto noise :(*noiseFunction)) {
		float value = noise.second.GetNoise(position.X,position.Z);
		if(value <= baseMaterials->at(noise.first)->Frequency) {
			materials.push_back(noise.first);
		}
	}
	if(materials.size() > 0) {
		return materials.at(0); 
	}
	return 1;
}	

int UCellularAutomata::assignOres(const shared_ptr<map<int, FMaterialDataTableStruct*>>& ores,
									const Vector2& position) {
	float random = (rand()*1.f)/ RAND_MAX;
	// UE_LOG(LogTemp, Warning, TEXT("Random: %f"), random);

	vector<int> chosenOres;
	for (auto ore : *ores) {
		if(random <= ore.second->Frequency) {
			chosenOres.push_back(ore.first);
		}
	}
	if(chosenOres.size()>0) {
		int material = chosenOres.at(rand()%chosenOres.size());
		UE_LOG(LogTemp, Warning, TEXT("material: %d"), material);

		return material;
	}
	return -1;
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "MarchingSquares.h"
#include <set>
#include <map>
#include <MagicGame2D\MeshGenerator.h>

// Sets default values for this component's properties
UMarchingSquares::UMarchingSquares()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMarchingSquares::BeginPlay()
{
	Super::BeginPlay();
	triangulator = Triangulator();
	// ...
	
}


// Called every frame
void UMarchingSquares::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UMarchingSquares::Generate(GenerationData *data) {
	getControlNodes(data);
	getSquares(data);
	triangulator.triangulate(data);
}


void UMarchingSquares::getControlNodes(GenerationData *data) {
	auto controlNodes = std::map<Vector2, std::shared_ptr<ControlNode>>{};
	int ones = 0;
	int zeros = 0;
	int i =0;
	UE_LOG(LogTemp, Warning, TEXT("Automata size: %d" ),data->getAutomata()->size());

	for(auto values : *data->getAutomata()) {
		auto pos = values.first;
		values.second == 1? ones++:zeros++;
		shared_ptr<ControlNode> node = make_shared<ControlNode>(pos,values.second);
		controlNodes.emplace(pos,node);
		i++;
	}
	UE_LOG(LogTemp, Warning, TEXT("Iterations: %d" ),i);

	UE_LOG(LogTemp, Warning, TEXT("Control On: %d" ),ones);
	UE_LOG(LogTemp, Warning, TEXT("Control Off: %d"),zeros);
	UE_LOG(LogTemp, Warning, TEXT("Control Total: %d"),(zeros+ones));
	data->setControlNodes(make_shared<std::map<Vector2, std::shared_ptr<ControlNode>>>(controlNodes));
}

bool UMarchingSquares::isControlNode(const Vector2& pos,
		GenerationData* data,
		const shared_ptr<BoundingBox>& boundingBox) {
	// UE_LOG(LogTemp, Warning, TEXT("Checking pos--: %f %f"),pos.X,pos.Z);

	if(!boundingBox->inside(pos)) return false;

	shared_ptr<ControlNode> node = (*(*data).getControlNodes())[pos];
	if(node != nullptr)	{
		// UE_LOG(LogTemp, Warning, TEXT("Not null pos--: %f %f"),pos.X,pos.Z);

	} else {
		// UE_LOG(LogTemp, Warning, TEXT("NULL pos--: %f %f"),pos.X,pos.Z);

	} 
	return node!=nullptr;
}

void UMarchingSquares::getSquares(GenerationData *data) {

	std::vector<shared_ptr<Square>> squares = vector<shared_ptr<Square>>();
	map<Vector2, shared_ptr<ControlNode>> controlNodes = *data->getControlNodes();
	std::shared_ptr<BoundingBox> boundigBox = data->getBoundingBox();

	for (pair<const Vector2,const shared_ptr<ControlNode>> values : controlNodes) {
		
		Vector2 topLeftPos = values.first;

		if(!isControlNode(topLeftPos,data,boundigBox)) continue;

		shared_ptr<ControlNode> topLeftNode = (controlNodes)[topLeftPos];

		Vector2 topRightPos = topLeftPos.add(Vector2(Globals::SQUARE_SIZE,0));
		if(!isControlNode(topRightPos,data,boundigBox)) continue;
		shared_ptr<ControlNode> topRightNode = (controlNodes)[topRightPos];

		Vector2 bottomRightPos = topLeftPos.add(Vector2(Globals::SQUARE_SIZE,-Globals::SQUARE_SIZE));
		if(!isControlNode(bottomRightPos,data,boundigBox)) continue;
		shared_ptr<ControlNode> bottomRightNode = (controlNodes)[bottomRightPos];

		Vector2 bottomLeftPos = topLeftPos.add(Vector2(0,-Globals::SQUARE_SIZE));
		if(!isControlNode(bottomLeftPos,data,boundigBox)) continue;
		shared_ptr<ControlNode> bottomLeftNode = (controlNodes)[bottomLeftPos];
	
		squares.push_back(std::move(std::make_shared<Square>(topLeftNode,topRightNode,bottomRightNode,bottomLeftNode)));

	}
	UE_LOG(LogTemp, Warning, TEXT("Squares Total: %d"),(squares.size()));

	
	data->setSquares(make_shared<vector<shared_ptr<Square>>>(squares));

}

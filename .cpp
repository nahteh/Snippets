// Nate repository

//must include for DRAW_SPHERE(Location)
#include "drawDebugHelpers.h"
#define DRAW_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, true);

//Draw on screen debug messages
//check if GEngine, avoid null pointer
if (GEngine)
{
	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, FString("Item OnScreen Message!"));
}

//standard log string
UE_LOG(LogTemp, Warning, TEXT("Begin Play Called!"));

//Log delta time as float
UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), DeltaTime);

//check engine, store and get: Object Name, combine: name+Item Name=Message
if (GEngine)
{
	FString Name = GetName();
	FString Message = FString::Printf(TEXT("Item Name: %s"), *Name);
	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, Message);

	UE_LOG(LogTemp, Warning, TEXT("Item Name: %s"), *Name);

}

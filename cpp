// Nate repository
/* 
  ___ ___                     .___            
 /   |   \   ____ _____     __| _/___________ 
/    ~    \_/ __ \\__  \   / __ |/ __ \_  __ \
\    Y    /\  ___/ / __ \_/ /_/ \  ___/|  | \/
 \___|_  /  \___  >____  /\____ |\___  >__|   
       \/       \/     \/      \/    \/       
*/
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "001 Sine Parameters")
	float Amplitude = .25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "001 Sine Parameters")
	float PeriodConstant = 5.f;

	UFUNCTION(BlueprintPure)
	float TransformedSine(float Value);

	UFUNCTION(BlueprintPure)
	float TransformedCos(float Value);

	template<typename T>
	T Avg(T First, T Second);

template<typename T>
inline T AItem::Avg(T First, T Second)
{
	return (First + Second) / 2;
}

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;

/*
________        ___.                 
\______ \   ____\_ |__  __ __  ____  
 |    |  \_/ __ \| __ \|  |  \/ ___\ 
 |    `   \  ___/| \_\ \  |  / /_/  >
/_______  /\___  >___  /____/\___  / 
        \/     \/    \/     /_____/  
                                  */
//Can Include in header
#include "drawDebugHelpers.h"
#include "Slash/DebugMacros.h"

//Dont forget to getworld() in BeginPlay()
UWorld* World = GetWorld();

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
SetActorLocation(FVector(0.f, 0.f, 50.f));
SetActorRotation(FRotator(0.f, 45.f, 0.f));
FVector Location = GetActorLocation();
FVector Forward = GetActorForwardVector();
DRAW_SPHERE(Location);
DRAW_LINE(Location, Location + Forward * 100.f);
DRAW_POINT(Location + Forward * 100.f);
DRAW_VECTOR(Location, Location + Forward * 100.f);

//single frame example,
DRAW_SPHERE_SingleFrame(GetActorLocation());
DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);

/*
   _____                                            __   
  /     \   _______  __ ____   _____   ____   _____/  |_ 
 /  \ /  \ /  _ \  \/ // __ \ /     \_/ __ \ /    \   __\
/    Y    (  <_> )   /\  ___/|  Y Y  \  ___/|   |  \  |  
\____|__  /\____/ \_/  \___  >__|_|  /\___  >___|  /__|  
        \/                 \/      \/     \/     \/      
*/
//Dont forget to getworld() in BeginPlay()
UWorld* World = GetWorld();
// movement rate = cm/s
float MovementRate = 50.f;
float RotationRate = 45.f;
// MovementRate * DeltaTime = cm/s * s/frame = cm/frame
AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));
AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));

RunningTime += DeltaTime;
float DeltaZ = Amplitude * FMath::Sin(RunningTime * PeriodConstant);
AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));
DRAW_SPHERE_SingleFrame(GetActorLocation());
DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);

//definitions made from sin/cos header
float AItem::TransformedSine(float Value)
{
	return Amplitude * FMath::Sin(Value * PeriodConstant);
}

float AItem::TransformedCos(float Value)
{
	return Amplitude * FMath::Cos(Value * PeriodConstant);
}

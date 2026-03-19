#include "MyActor.h"

AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = true;

    CurrentLocation = FVector(0.0f, 50.0f, 0.0f);
    TotalDistance = 0.0f;
    EventCount = 0;
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    SetActorLocation(CurrentLocation);

    for (int32 i = 1; i <= 10; i++)
    {
        Move();
        TriggerEvent();

        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan,
                FString::Printf(TEXT("Step %d - Location: %s"), i, *CurrentLocation.ToString()));
        }
    }

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Yellow,
            FString::Printf(TEXT("[Final Report] Total Distance: %.2f | Total Events: %d"), TotalDistance, EventCount));
    }
}

void AMyActor::Move()
{
    FVector PreviousLocation = CurrentLocation;

    float RandX = FMath::FRandRange(-100.f, 100.f);
    float RandY = FMath::FRandRange(-100.f, 100.f);

    CurrentLocation.X += RandX;
    CurrentLocation.Y += RandY;

    TotalDistance += FVector::Dist(PreviousLocation, CurrentLocation);
}

void AMyActor::TriggerEvent()
{
    if (FMath::RandRange(0, 1) == 0)
    {
        EventCount++;

        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT(">> Event Triggered! <<"));
        }
    }
}

void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
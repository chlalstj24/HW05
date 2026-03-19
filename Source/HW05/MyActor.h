#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HW05_API AMyActor : public AActor
{
    GENERATED_BODY()

public:
    AMyActor();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // 현재 위치
    FVector CurrentLocation;

    // [도전] 총 이동 거리 및 이벤트 발생 횟수 변수
    float TotalDistance;
    int32 EventCount;

    // 필수 기능 함수
    void Move();

    // [도전] 50% 확률 이벤트 함수
    void TriggerEvent();
};
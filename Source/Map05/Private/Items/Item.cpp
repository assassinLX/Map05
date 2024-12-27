// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/Item.h"

DEFINE_LOG_CATEGORY(ItemLog);


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(ItemLog, Warning, TEXT("Come on! Be patient!!!"));
	// 在屏幕上显示调试信息
	// 使用GEngine的AddOnScreenDebugMessage函数在屏幕上显示消息
	// 参数说明:
	// 1 - Key值，用于标识消息
	// 60.f - 显示时间(秒)
	// FColor::Black - 文本颜色
	// FString - 要显示的文本内容
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1,60.f,FColor::Black,FString("Item OnScreen Message!"));
	}
	// GEngine是虚幻引擎的全局引擎指针，提供了许多游戏引擎级别的功能
	// 它可以用来访问游戏的各种系统功能，比如:
	// - 在屏幕上显示调试信息(AddOnScreenDebugMessage)
	// - 访问游戏世界(GetWorld)
	// - 管理音频、材质等资源
	// 使用前应该始终检查GEngine是否为空，因为在某些情况下它可能未初始化
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(ItemLog, Warning, TEXT("DeltaTime: %f"), DeltaTime);

	if (GEngine)
	{
		FString Name = GetName();
		FString DebugMessage = FString::Printf(TEXT("Item Name: %s"), *Name);
		GEngine->AddOnScreenDebugMessage(1,60.f,FColor::Black,DebugMessage);
		// 在Unreal Engine中，FString是一个类，它包含了一个指向字符数据的指针
		// 当我们使用 *Name 时，* 运算符是FString类重载的运算符
		// 它返回指向实际字符数据的TCHAR*指针（即字符串的原始数据）
		// 这是因为FString::Printf需要原始的字符串数据而不是FString对象
		// 所以我们使用 *Name 来获取FString对象中存储的实际字符串数据

		UE_LOG(ItemLog, Warning, TEXT("Item Name: %s"), *Name);

	}
	//这里提到一个观点，尽可能使用Unreal Engine的函数，这是跨平台的，保证兼容性，比如FString，而不是传统C++函数
	//因为C++的函数是平台相关的，不保证兼容性。
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "SlashCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ASlashCharacter::ASlashCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f,400.f,0.f);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 300.f;

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(CameraBoom);
}

void ASlashCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASlashCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0)
	{
		//FVector forward = GetActorForwardVector();
		//AddMovementInput(forward, Value);

		//这行代码获取当前控制器的旋转（即玩家的视角方向），并将其存储在 ControlRotation 变量中。FRotator 是一个表示旋转的结构体，包含俯仰（Pitch）、偏航（Yaw）和滚转（Roll）三个分量。
		const FRotator ControlRotation = GetControlRotation();

		//这里创建了一个新的 FRotator 对象 YawRotation，它的俯仰和滚转分量都设置为 0，而偏航分量则使用了从 ControlRotation 中获取的偏航值。这意味着 YawRotation 只表示水平方向的旋转。
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);
		
		//这行代码使用 YawRotation 创建一个旋转矩阵，并从中获取 X 轴的单位向量。FRotationMatrix 是一个用于表示旋转的矩阵，GetUnitAxis(EAxis::X) 方法返回该矩阵在 X 轴方向上的单位向量。这个单位向量表示角色在当前视角下的前进方向。
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(Direction, Value);
	}
}

void ASlashCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ASlashCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void ASlashCharacter::MoveRight(float Value)
{
	if (Controller && Value != 0) 
	{
		//FVector Right = GetActorRightVector();
		//AddMovementInput(Right, Value);
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);

	}

}

void ASlashCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASlashCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ASlashCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &ASlashCharacter::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &ASlashCharacter::LookUp);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ASlashCharacter::MoveRight);
}


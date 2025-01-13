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

		//���д����ȡ��ǰ����������ת������ҵ��ӽǷ��򣩣�������洢�� ControlRotation �����С�FRotator ��һ����ʾ��ת�Ľṹ�壬����������Pitch����ƫ����Yaw���͹�ת��Roll������������
		const FRotator ControlRotation = GetControlRotation();

		//���ﴴ����һ���µ� FRotator ���� YawRotation�����ĸ����͹�ת����������Ϊ 0����ƫ��������ʹ���˴� ControlRotation �л�ȡ��ƫ��ֵ������ζ�� YawRotation ֻ��ʾˮƽ�������ת��
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);
		
		//���д���ʹ�� YawRotation ����һ����ת���󣬲����л�ȡ X ��ĵ�λ������FRotationMatrix ��һ�����ڱ�ʾ��ת�ľ���GetUnitAxis(EAxis::X) �������ظþ����� X �᷽���ϵĵ�λ�����������λ������ʾ��ɫ�ڵ�ǰ�ӽ��µ�ǰ������
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


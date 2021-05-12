// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NigelsExpedition/GameSave.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameSave() {}
// Cross Module References
	NIGELSEXPEDITION_API UClass* Z_Construct_UClass_UGameSave_NoRegister();
	NIGELSEXPEDITION_API UClass* Z_Construct_UClass_UGameSave();
	ENGINE_API UClass* Z_Construct_UClass_USaveGame();
	UPackage* Z_Construct_UPackage__Script_NigelsExpedition();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	void UGameSave::StaticRegisterNativesUGameSave()
	{
	}
	UClass* Z_Construct_UClass_UGameSave_NoRegister()
	{
		return UGameSave::StaticClass();
	}
	struct Z_Construct_UClass_UGameSave_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PlayerLocation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameSave_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USaveGame,
		(UObject* (*)())Z_Construct_UPackage__Script_NigelsExpedition,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameSave_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "GameSave.h" },
		{ "ModuleRelativePath", "GameSave.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameSave_Statics::NewProp_PlayerLocation_MetaData[] = {
		{ "Category", "GameSave" },
		{ "ModuleRelativePath", "GameSave.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGameSave_Statics::NewProp_PlayerLocation = { "PlayerLocation", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameSave, PlayerLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UGameSave_Statics::NewProp_PlayerLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameSave_Statics::NewProp_PlayerLocation_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameSave_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameSave_Statics::NewProp_PlayerLocation,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameSave_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameSave>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameSave_Statics::ClassParams = {
		&UGameSave::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGameSave_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGameSave_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGameSave_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameSave_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameSave()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameSave_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameSave, 3315846520);
	template<> NIGELSEXPEDITION_API UClass* StaticClass<UGameSave>()
	{
		return UGameSave::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameSave(Z_Construct_UClass_UGameSave, &UGameSave::StaticClass, TEXT("/Script/NigelsExpedition"), TEXT("UGameSave"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameSave);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

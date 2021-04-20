// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NigelsExpedition/Nigel_GameMode_BP.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNigel_GameMode_BP() {}
// Cross Module References
	NIGELSEXPEDITION_API UClass* Z_Construct_UClass_ANigel_GameMode_BP_NoRegister();
	NIGELSEXPEDITION_API UClass* Z_Construct_UClass_ANigel_GameMode_BP();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_NigelsExpedition();
// End Cross Module References
	void ANigel_GameMode_BP::StaticRegisterNativesANigel_GameMode_BP()
	{
	}
	UClass* Z_Construct_UClass_ANigel_GameMode_BP_NoRegister()
	{
		return ANigel_GameMode_BP::StaticClass();
	}
	struct Z_Construct_UClass_ANigel_GameMode_BP_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANigel_GameMode_BP_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_NigelsExpedition,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANigel_GameMode_BP_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Nigel_GameMode_BP.h" },
		{ "ModuleRelativePath", "Nigel_GameMode_BP.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANigel_GameMode_BP_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANigel_GameMode_BP>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ANigel_GameMode_BP_Statics::ClassParams = {
		&ANigel_GameMode_BP::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ANigel_GameMode_BP_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANigel_GameMode_BP_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANigel_GameMode_BP()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ANigel_GameMode_BP_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANigel_GameMode_BP, 3742622670);
	template<> NIGELSEXPEDITION_API UClass* StaticClass<ANigel_GameMode_BP>()
	{
		return ANigel_GameMode_BP::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANigel_GameMode_BP(Z_Construct_UClass_ANigel_GameMode_BP, &ANigel_GameMode_BP::StaticClass, TEXT("/Script/NigelsExpedition"), TEXT("ANigel_GameMode_BP"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANigel_GameMode_BP);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

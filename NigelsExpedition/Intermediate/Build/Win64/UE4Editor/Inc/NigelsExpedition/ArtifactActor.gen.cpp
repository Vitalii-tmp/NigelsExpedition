// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NigelsExpedition/ArtifactActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeArtifactActor() {}
// Cross Module References
	NIGELSEXPEDITION_API UClass* Z_Construct_UClass_AArtifactActor_NoRegister();
	NIGELSEXPEDITION_API UClass* Z_Construct_UClass_AArtifactActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_NigelsExpedition();
// End Cross Module References
	void AArtifactActor::StaticRegisterNativesAArtifactActor()
	{
	}
	UClass* Z_Construct_UClass_AArtifactActor_NoRegister()
	{
		return AArtifactActor::StaticClass();
	}
	struct Z_Construct_UClass_AArtifactActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AArtifactActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_NigelsExpedition,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AArtifactActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ArtifactActor.h" },
		{ "ModuleRelativePath", "ArtifactActor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AArtifactActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AArtifactActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AArtifactActor_Statics::ClassParams = {
		&AArtifactActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AArtifactActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AArtifactActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AArtifactActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AArtifactActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AArtifactActor, 835135275);
	template<> NIGELSEXPEDITION_API UClass* StaticClass<AArtifactActor>()
	{
		return AArtifactActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AArtifactActor(Z_Construct_UClass_AArtifactActor, &AArtifactActor::StaticClass, TEXT("/Script/NigelsExpedition"), TEXT("AArtifactActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AArtifactActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

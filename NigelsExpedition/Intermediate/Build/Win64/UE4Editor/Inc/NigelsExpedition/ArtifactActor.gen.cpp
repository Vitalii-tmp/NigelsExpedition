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
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
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
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BoxComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BoxComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AArtifactActor_Statics::NewProp_BoxComponent_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ArtifactActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AArtifactActor_Statics::NewProp_BoxComponent = { "BoxComponent", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AArtifactActor, BoxComponent), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AArtifactActor_Statics::NewProp_BoxComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AArtifactActor_Statics::NewProp_BoxComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AArtifactActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AArtifactActor_Statics::NewProp_BoxComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AArtifactActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AArtifactActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AArtifactActor_Statics::ClassParams = {
		&AArtifactActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AArtifactActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AArtifactActor_Statics::PropPointers),
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
	IMPLEMENT_CLASS(AArtifactActor, 1563295463);
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

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef NIGELSEXPEDITION_Nigel_generated_h
#error "Nigel.generated.h already included, missing '#pragma once' in Nigel.h"
#endif
#define NIGELSEXPEDITION_Nigel_generated_h

#define NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_SPARSE_DATA
#define NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execLoadGame); \
	DECLARE_FUNCTION(execSaveGame); \
	DECLARE_FUNCTION(execOnOverlapEnd); \
	DECLARE_FUNCTION(execOnOverlapBegin); \
	DECLARE_FUNCTION(execRestartLvl);


#define NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLoadGame); \
	DECLARE_FUNCTION(execSaveGame); \
	DECLARE_FUNCTION(execOnOverlapEnd); \
	DECLARE_FUNCTION(execOnOverlapBegin); \
	DECLARE_FUNCTION(execRestartLvl);


#define NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANigel(); \
	friend struct Z_Construct_UClass_ANigel_Statics; \
public: \
	DECLARE_CLASS(ANigel, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NigelsExpedition"), NO_API) \
	DECLARE_SERIALIZER(ANigel)


#define NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_INCLASS \
private: \
	static void StaticRegisterNativesANigel(); \
	friend struct Z_Construct_UClass_ANigel_Statics; \
public: \
	DECLARE_CLASS(ANigel, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NigelsExpedition"), NO_API) \
	DECLARE_SERIALIZER(ANigel)


#define NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ANigel(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANigel) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANigel); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANigel); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANigel(ANigel&&); \
	NO_API ANigel(const ANigel&); \
public:


#define NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANigel(ANigel&&); \
	NO_API ANigel(const ANigel&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANigel); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANigel); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANigel)


#define NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_PRIVATE_PROPERTY_OFFSET
#define NigelsExpedition_Source_NigelsExpedition_Nigel_h_18_PROLOG
#define NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_PRIVATE_PROPERTY_OFFSET \
	NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_SPARSE_DATA \
	NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_RPC_WRAPPERS \
	NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_INCLASS \
	NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_PRIVATE_PROPERTY_OFFSET \
	NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_SPARSE_DATA \
	NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_INCLASS_NO_PURE_DECLS \
	NigelsExpedition_Source_NigelsExpedition_Nigel_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NIGELSEXPEDITION_API UClass* StaticClass<class ANigel>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID NigelsExpedition_Source_NigelsExpedition_Nigel_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

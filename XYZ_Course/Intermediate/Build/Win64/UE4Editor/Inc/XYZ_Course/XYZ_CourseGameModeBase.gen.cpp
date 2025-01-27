// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "XYZ_Course/XYZ_CourseGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeXYZ_CourseGameModeBase() {}
// Cross Module References
	XYZ_COURSE_API UClass* Z_Construct_UClass_AXYZ_CourseGameModeBase_NoRegister();
	XYZ_COURSE_API UClass* Z_Construct_UClass_AXYZ_CourseGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_XYZ_Course();
// End Cross Module References
	void AXYZ_CourseGameModeBase::StaticRegisterNativesAXYZ_CourseGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AXYZ_CourseGameModeBase_NoRegister()
	{
		return AXYZ_CourseGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AXYZ_CourseGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AXYZ_CourseGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_XYZ_Course,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AXYZ_CourseGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "XYZ_CourseGameModeBase.h" },
		{ "ModuleRelativePath", "XYZ_CourseGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AXYZ_CourseGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AXYZ_CourseGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AXYZ_CourseGameModeBase_Statics::ClassParams = {
		&AXYZ_CourseGameModeBase::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AXYZ_CourseGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AXYZ_CourseGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AXYZ_CourseGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AXYZ_CourseGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AXYZ_CourseGameModeBase, 2912563842);
	template<> XYZ_COURSE_API UClass* StaticClass<AXYZ_CourseGameModeBase>()
	{
		return AXYZ_CourseGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AXYZ_CourseGameModeBase(Z_Construct_UClass_AXYZ_CourseGameModeBase, &AXYZ_CourseGameModeBase::StaticClass, TEXT("/Script/XYZ_Course"), TEXT("AXYZ_CourseGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AXYZ_CourseGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

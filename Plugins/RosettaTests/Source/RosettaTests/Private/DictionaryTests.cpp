#include "DictionaryTests.h"

#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"

#include "Dictionary.h"

UDictionary* GenerateTestDictionary()
{
	UDictionary* Dict = NewObject<UDictionary>();
	Dict->AddEntry("Original1", "Translation1");
	Dict->AddEntry("Original2");
	Dict->AddEntry("Original3", "Translation3");
	return Dict;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGameTest, "DictionaryTests.DeleteAnyEntry",
	EAutomationTestFlags::EditorContext |
	EAutomationTestFlags::ClientContext |
	EAutomationTestFlags::ProductFilter)
bool FGameTest::RunTest(const FString& Parameters) {
	UDictionary* Dict = GenerateTestDictionary();

	int EntriesInitialCount = Dict->GetEntriesCount();

	Dict->DeleteEntry(0);

	FString FailMessage = "expected entries count to be " + FString::FromInt(EntriesInitialCount - 1) + ", was " + FString::FromInt(Dict->GetEntriesCount());
	TestTrue(FailMessage, EntriesInitialCount - 1 == Dict->GetEntriesCount());

	return true;
}

//#include "Engine.h"
//#include "EngineUtils.h"
//
//#include "YourGameModeBase.h"
//#include "MyEssentialActor.h"
//
//// Copy of the hidden method GetAnyGameWorld() in AutomationCommon.cpp.
//// Marked as temporary there, hence, this one is temporary, too.
//UWorld* GetTestWorld() {
//	const TIndirectArray<FWorldContext>& WorldContexts = GEngine->GetWorldContexts();
//	for (const FWorldContext& Context : WorldContexts) {
//		if (((Context.WorldType == EWorldType::PIE) || (Context.WorldType == EWorldType::Game))
//			&& (Context.World() != nullptr)) {
//			return Context.World();
//		}
//	}
//
//	return nullptr;
//}
//
//IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGameTest, "YourGame.Game",
//	EAutomationTestFlags::Editor |
//	EAutomationTestFlags::ClientContext |
//	EAutomationTestFlags::ProductFilter)
//
//	bool FGameTest::RunTest(const FString& Parameters) {
//	AutomationOpenMap(TEXT("/Game/Levels/StartupLevel"));
//
//	UWorld* world = GetTestWorld();
//
//	TestTrue("GameMode class is set correctly",
//		world->GetAuthGameMode()->IsA<YourGameModeBase>());
//	TestTrue("Essential actor is spawned",
//		TActorIterator<AMyEssentialActor>(world));
//
//	return true;
//}
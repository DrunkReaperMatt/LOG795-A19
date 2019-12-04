#include "DictionaryTests.h"

#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"

#include "Dictionary.h"
#include "DictionaryEntry.h"

UDictionary* GenerateTestDictionary(bool autoGenerateEntries)
{
	UDictionary* Dict = NewObject<UDictionary>();
	if (autoGenerateEntries)
	{
		Dict->AddEntry("Original1", "Translation1");
		Dict->AddEntry("Original2");
		Dict->AddEntry("Original3", "Translation3");
	}
	return Dict;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDictTestDeleteEntryAny, "DictionaryTests.DeleteEntryAny",
	EAutomationTestFlags::EditorContext |
	EAutomationTestFlags::ClientContext |
	EAutomationTestFlags::ProductFilter)
bool FDictTestDeleteEntryAny::RunTest(const FString& Parameters) {
	UDictionary* Dict = GenerateTestDictionary(true);

	int EntriesInitialCount = Dict->GetEntriesCount();
	int ExpectedEntriesCount = EntriesInitialCount - 1;

	Dict->DeleteEntry(0);

	FString FailMessage = "expected entries count to be " + FString::FromInt(ExpectedEntriesCount) + ", was " + FString::FromInt(Dict->GetEntriesCount());
	TestTrue(FailMessage, ExpectedEntriesCount == Dict->GetEntriesCount());

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDictTestAddEntryAny, "DictionaryTests.AddEntryAny",
	EAutomationTestFlags::EditorContext |
	EAutomationTestFlags::ClientContext |
	EAutomationTestFlags::ProductFilter)
bool FDictTestAddEntryAny::RunTest(const FString& Parameters) {
	UDictionary* Dict = GenerateTestDictionary(false);

	int EntriesInitialCount = Dict->GetEntriesCount();
	int ExpectedEntriesCount = EntriesInitialCount + 1;

	Dict->AddEntry("Original1");

	FString FailMessage = "expected entries count to be " + FString::FromInt(ExpectedEntriesCount) + ", was " + FString::FromInt(Dict->GetEntriesCount());
	TestTrue(FailMessage, ExpectedEntriesCount == Dict->GetEntriesCount());

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDictTestAddEntryOriginalExisting, "DictionaryTests.AddEntryOriginalExisting",
	EAutomationTestFlags::EditorContext |
	EAutomationTestFlags::ClientContext |
	EAutomationTestFlags::ProductFilter)
bool FDictTestAddEntryOriginalExisting::RunTest(const FString& Parameters) {
	UDictionary* Dict = GenerateTestDictionary(true);

	int EntriesInitialCount = Dict->GetEntriesCount();
	int ExpectedEntriesCount = EntriesInitialCount;

	Dict->AddEntry("Original1");

	FString FailMessage = "expected entries count to be " + FString::FromInt(ExpectedEntriesCount) + ", was " + FString::FromInt(Dict->GetEntriesCount());
	TestTrue(FailMessage, ExpectedEntriesCount == Dict->GetEntriesCount());

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDictTestUpdateEntryOriginalAny, "DictionaryTests.UpdateEntryOriginalAny",
	EAutomationTestFlags::EditorContext |
	EAutomationTestFlags::ClientContext |
	EAutomationTestFlags::ProductFilter)
bool FDictTestUpdateEntryOriginalAny::RunTest(const FString& Parameters) {
	UDictionary* Dict = GenerateTestDictionary(true);

	FString InitialOriginal = Dict->GetEntry(0)->GetOriginal();
	FString NewOriginal = "NewOriginal1";
	Dict->UpdateEntryOriginal(0, NewOriginal);

	FString FailMessage = "expected entry's original to be " + NewOriginal + ", was " + Dict->GetEntry(0)->GetOriginal();
	TestTrue(FailMessage, Dict->GetEntry(0)->GetOriginal() != InitialOriginal);

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDictTestUpdateEntryOriginalExisting, "DictionaryTests.UpdateEntryOriginalExisting",
	EAutomationTestFlags::EditorContext |
	EAutomationTestFlags::ClientContext |
	EAutomationTestFlags::ProductFilter)
bool FDictTestUpdateEntryOriginalExisting::RunTest(const FString& Parameters) {
	UDictionary* Dict = GenerateTestDictionary(true);

	FString InitialOriginal = Dict->GetEntry(0)->GetOriginal();
	Dict->UpdateEntryOriginal(0, "Original2");

	FString FailMessage = "expected entry's original to be " + InitialOriginal + ", was " + Dict->GetEntry(0)->GetOriginal();
	TestTrue(FailMessage, Dict->GetEntry(0)->GetOriginal() == InitialOriginal);

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDictTestUpdateEntryTranslationAny, "DictionaryTests.UpdateEntryTranslationAny",
	EAutomationTestFlags::EditorContext |
	EAutomationTestFlags::ClientContext |
	EAutomationTestFlags::ProductFilter)
bool FDictTestUpdateEntryTranslationAny::RunTest(const FString& Parameters) {
	UDictionary* Dict = GenerateTestDictionary(true);

	FString InitialTranslation = Dict->GetEntry(0)->GetTranslation();
	FString NewTranslation = "NewTranslation1";
	Dict->UpdateEntryTranslation(0, "NewTranslation1");

	FString FailMessage = "expected entry's translation to be " + NewTranslation + ", was " + Dict->GetEntry(0)->GetTranslation();
	TestTrue(FailMessage, Dict->GetEntry(0)->GetTranslation() != InitialTranslation);

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDictTestUpdateEntryTranslationExisting, "DictionaryTests.UpdateEntryTranslationExisting",
	EAutomationTestFlags::EditorContext |
	EAutomationTestFlags::ClientContext |
	EAutomationTestFlags::ProductFilter)
bool FDictTestUpdateEntryTranslationExisting::RunTest(const FString& Parameters) {
	UDictionary* Dict = GenerateTestDictionary(true);

	FString InitialTranslation = Dict->GetEntry(0)->GetTranslation();
	FString NewTranslation = "Translation3";
	Dict->UpdateEntryTranslation(0, "Translation3");

	FString FailMessage = "expected entry's translation to be " + NewTranslation + ", was " + Dict->GetEntry(0)->GetTranslation();
	TestTrue(FailMessage, Dict->GetEntry(0)->GetTranslation() != InitialTranslation);

	return true;
}

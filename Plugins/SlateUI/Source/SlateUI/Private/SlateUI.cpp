// Copyright Epic Games, Inc. All Rights Reserved.

#include "SlateUI.h"
#include "SlateModuleWidget.h"
#include "SlateListViewExample.h"

#include "Widgets/SWindow.h"
#include "Widgets/Text/STextBlock.h"

#include "Framework/Application/SlateApplication.h"

#include "ToolMenus.h"

#define LOCTEXT_NAMESPACE "FSlateUIModule"

void FSlateUIModule::StartupModule()
{
	RegisterMenus();
}

void FSlateUIModule::ShutdownModule()
{

}

void FSlateUIModule::RegisterMenus(){
	FToolMenuOwnerScoped OwnerScoped(this);

	UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
	FToolMenuSection& Section = Menu->AddSection("SlateUISection", LOCTEXT("PMC", "PMC"));
	Section.AddMenuEntry(
		"OpenSlateWindow",
        LOCTEXT("OpenSlateWindow", "Open Slate Window"),
        LOCTEXT("OpenSlateWindowTooltip", "Open a custom Slate Window."),
        FSlateIcon(),
        FUIAction(FExecuteAction::CreateRaw(this, &FSlateUIModule::OpenSlateWindow))
	);
}

void FSlateUIModule::OpenSlateWindow(){
	TSharedRef<SWindow> NewWindow = SNew(SWindow)
		.Title(LOCTEXT("My Sound Table", "My Slate Window"))
		.ClientSize(FVector2D(400, 300))
		.SupportsMinimize(true)
		.SupportsMaximize(true);

	NewWindow->SetContent(
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
			.AutoHeight()[
				SNew(SSlateListViewExample)
			]
			+ SVerticalBox::Slot()
			.AutoHeight()[
				SNew(SSlateModuleWidget)
			]
	);

	FSlateApplication::Get().AddWindow(NewWindow);
}

FReply FSlateUIModule::OnButtonClick(){
	UE_LOG(LogTemp, Log, TEXT("Hello World"));
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSlateUIModule, SlateUI)
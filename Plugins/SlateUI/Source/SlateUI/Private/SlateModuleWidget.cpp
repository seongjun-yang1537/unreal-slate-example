#include "SlateModuleWidget.h"

#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Notifications/SProgressBar.h" 

#include "ItemData.h"
#include "Widgets/Views/SListView.h"

void SSlateModuleWidget::Construct(const FArguments& InArgs){
    ChildSlot
    [
        SNew(SScrollBox)
        + SScrollBox::Slot()
        [
            SNew(SButton)
                .Text(FText::FromString(TEXT("Hi")))
                .OnClicked(this, &SSlateModuleWidget::ButtonPressed)
        ]
        +SScrollBox::Slot()
        [
            SAssignNew(ListViewWidget, SListView<TSharedPtr<FString>>)
                .ItemHeight(128)
                .ListItemsSource(&Items)
                .OnGenerateRow(this, &SSlateModuleWidget::OnGenerateRowForList)
        ]
    ];
}

FReply SSlateModuleWidget::OnCustomButtonClick(){
    UE_LOG(LogTemp, Log, TEXT("My Button"));
    return FReply::Handled();
}

FReply SSlateModuleWidget::ButtonPressed()
{
	Items.Add(MakeShareable(new FString("Hello 1")));
	ListViewWidget->RequestListRefresh();

	return FReply::Handled();
}


TSharedRef<ITableRow> SSlateModuleWidget::OnGenerateRowForList(TSharedPtr<FString> Item, const TSharedRef<STableViewBase>& OwnerTable)
{
	//Create the row
	return
		SNew(STableRow< TSharedPtr<FString> >, OwnerTable)
		.Padding(2.0f)[
            SNew(SHorizontalBox)
            + SHorizontalBox::Slot()[
                SNew(STextBlock)
                    .Text(FText::FromString(*Item.Get()))
            ]
            + SHorizontalBox::Slot()[
                SNew(SProgressBar)
                    .Percent(0.75)
            ]
            + SHorizontalBox::Slot()[
                SNew(STextBlock)
                    .Text(FText::FromString(*Item.Get()))
            ]
                        + SHorizontalBox::Slot()[
                SNew(STextBlock)
                    .Text(FText::FromString(*Item.Get()))
            ]
            + SHorizontalBox::Slot()[
                SNew(STextBlock)
                    .Text(FText::FromString(*Item.Get()))
            ]
            + SHorizontalBox::Slot()[
                SNew(STextBlock)
                    .Text(FText::FromString(*Item.Get()))
            ]
		];
}
#include "SlateListViewExample.h"
#include "ItemData.h"

#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Views/SListView.h"

#define CLASS SSlateListViewExample

void CLASS::Construct(const FArguments& InArgs){
    ChildSlot
    [
        SNew(SScrollBox)
        + SScrollBox::Slot()
        [
            SNew(SButton)
                .Text(FText::FromString("Add Element"))
                .OnClicked(this, &CLASS::ButtonPressed)
        ]
        + SScrollBox::Slot()
        [
            SAssignNew(ListViewWidget, SListView<TSharedPtr<FString>>)
                .ItemHeight(24)
                .ListItemsSource(&Items)
                .OnGenerateRow(this, &CLASS::OnGenerateRowForList)
        ]
    ];
}

FReply CLASS::ButtonPressed(){
    Items.Add(MakeShareable(new FString("Hello")));
    ListViewWidget->RequestListRefresh();
    return FReply::Handled();
}

TSharedRef<ITableRow> CLASS::OnGenerateRowForList(TSharedPtr<FString> Item, const TSharedRef<STableViewBase>& OwnerTable){
    return SNew(STableRow<TSharedPtr<FString>>, OwnerTable)
        .Padding(2.0f)[
            SNew(SHorizontalBox)
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
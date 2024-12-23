#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SLATEUI_API SSlateListViewExample : public SCompoundWidget{
public:
    SLATE_BEGIN_ARGS(SSlateListViewExample){}
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs);
    FReply ButtonPressed();

    TSharedRef<ITableRow> OnGenerateRowForList(TSharedPtr<FString> Item, const TSharedRef<STableViewBase>& OwnerTable);

    TArray<TSharedPtr<FString>> Items;
    TSharedPtr<SListView<TSharedPtr<FString>>> ListViewWidget;
};
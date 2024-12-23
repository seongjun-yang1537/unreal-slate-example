#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SLATEUI_API SSlateModuleWidget : public SCompoundWidget {
public:
    SLATE_BEGIN_ARGS(SSlateModuleWidget){}
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs);
    FReply ButtonPressed();

    TSharedRef<ITableRow> OnGenerateRowForList(TSharedPtr<FString> Item, const TSharedRef<STableViewBase>& OwnerTable);

    TArray<TSharedPtr<FString>> Items;
    TSharedPtr<SListView<TSharedPtr<FString>>> ListViewWidget;
private:
    FReply OnCustomButtonClick();
};
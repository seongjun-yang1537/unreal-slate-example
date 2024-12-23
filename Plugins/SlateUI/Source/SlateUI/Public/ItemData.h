#pragma once

#include "CoreMinimal.h"
#include "ItemData.generated.h"

/**
 * 
 */
class SLATEUI_API ItemData
{
public:
	ItemData();
	~ItemData();
};

USTRUCT()
struct SLATEUI_API FItemData{
	GENERATED_USTRUCT_BODY()	

	UPROPERTY()
	FString ItemText;

	FItemData() : ItemText(TEXT("default")) {}
	FItemData(const FString& InItemText) : ItemText(InItemText){}
};
/*
* ============================================================================
*  Name     : CDummyProjDialog from DummyProjDialog.h
*  Part of  : DummyProj
*  Created  : 13/04/2005 by Mike Howson
*  Implementation notes:
*     Initial content was generated by Series 60 AppWizard.
*  Version  :
*  Copyright: Penrillian
* ============================================================================
*/

// INCLUDE FILES
#include    "DummyProjDialog.h"

#include <eiklabel.h>  // for example label control
#include <avkon.hrh>
#include <aknappui.h>
#include <EikEnv.h>
#include <eikclbd.h>
#include <AknLists.h>
#include <barsread.h>
#include <dummyproj.rsg>
#include <badesca.h>
#include <akndialog.h> 


// ================= MEMBER FUNCTIONS =======================



// Destructor
CDummyProjDialog::~CDummyProjDialog()
    {
		delete iListBox;
    }

// ---------------------------------------------------------
// CDummyProjDialog::OkToExitL(TInt aButtonId)
// called by framework when the softkey is pressed
// ---------------------------------------------------------
//
TBool CDummyProjDialog::OkToExitL(TInt aButtonId)
{
    // Translate the button presses into commands for the appui & current
    // view to handle
    if ( aButtonId == EAknSoftkeyOptions )
        {
        iAvkonAppUi->ProcessCommandL( EAknSoftkeyOptions );
        }
    else if ( aButtonId == EAknSoftkeyBack )
        {
        iAvkonAppUi->ProcessCommandL( EEikCmdExit );
        }
    
    return EFalse;
}

// ---------------------------------------------------------
// CDummyProjDialog::PreLayoutDynInitL();
// called by framework before dialog is shown 
// ---------------------------------------------------------
//
void CDummyProjDialog::PreLayoutDynInitL()
    {
	TResourceReader reader;
	
	iEikonEnv->CreateResourceReaderLC(reader, R_DUMMYPROJ_DIALOG_LISTBOX);
	iListBox = new (ELeave) CAknSingleStyleListBox;
	iListBox->SetMopParent(this);
	iListBox->SetContainerWindowL(*this);
	iListBox->ConstructFromResourceL(reader);
	CleanupStack::PopAndDestroy(); // reader

	iListBox->CreateScrollBarFrameL(ETrue);
	iListBox->ScrollBarFrame()->SetScrollBarVisibilityL(CEikScrollBarFrame::EOff, CEikScrollBarFrame::EAuto);
	iListBox->ActivateL();
}

void CDummyProjDialog::PostLayoutDynInitL()
{
	iListBox->SetRect(this->Rect());
}


TKeyResponse CDummyProjDialog::OfferKeyEventL(const TKeyEvent& aKeyEvent, TEventCode aEventCode)
{
	return iListBox->OfferKeyEventL(aKeyEvent, aEventCode);
}


void CDummyProjDialog::AddListboxItemL(const TDesC& aPtr)
{
	CTextListBoxModel* model = iListBox->Model();
	CDesCArray* itemArray=STATIC_CAST(CDesCArray*,model->ItemTextArray());
	itemArray->AppendL(aPtr);
	iListBox->HandleItemAdditionL();
}

TInt CDummyProjDialog::CountComponentControls() const
{
	if (iListBox)
		return 1;
	return 0;
}
CCoeControl* CDummyProjDialog::ComponentControl(TInt aIndex) const
{
	switch (aIndex)
	{
	case 0:
		{
			return iListBox;
		}
	default:
		{
			ASSERT(EFalse);
			break;
		}
	}
	return NULL;
}

// End of File

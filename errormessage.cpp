#include "errormessage.h"

ErrorMessage::ErrorMessage()
{

}

void ErrorMessage::showElementAlreadyThereError()
{
	//Show error if an element already exists there.
	QMessageBox elementExistsAlreadyAlert;
	elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
	elementExistsAlreadyAlert.setText("An element already exists here.");
	elementExistsAlreadyAlert.exec();
}

void ErrorMessage::showLowNumOfLinkedTrackErrorMessage()
{
	QMessageBox lowLinkedTrack;
	lowLinkedTrack.setIcon(QMessageBox::Critical);
	lowLinkedTrack.setText("There needs to be 2 or more Linked tracks to connect! Number of Linked Track also has to be even!");
	lowLinkedTrack.exec();
}

void ErrorMessage::showOddNumOfLinkedTrackErrorMessage()
{
	//Show oddNumOfLinkTrack error box.
	QMessageBox oddNumofLinkedTrack;
	oddNumofLinkedTrack.setIcon(QMessageBox::Critical);
	oddNumofLinkedTrack.setText("Cannot link track. Odd number of LinkedTrack");
	oddNumofLinkedTrack.exec();
}

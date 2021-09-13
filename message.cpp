#include "message.h"

Message::Message()
{

}

//Success

void Message::showAllTrackConnecedSuccessMessage()
{
	QMessageBox allConnectedBox;
	//allConnectedBox.setIcon(QMessageBox::Accepted);
	allConnectedBox.setText("All track connected");
	allConnectedBox.exec();
}


//Errors

void Message::showElementAlreadyThereErrorMessage()
{
	//Show error if an element already exists there.
	QMessageBox elementExistsAlreadyAlert;
	elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
	elementExistsAlreadyAlert.setText("An element already exists here.");
	elementExistsAlreadyAlert.exec();
}

void Message::showLowNumOfLinkedTrackErrorMessage()
{
	QMessageBox lowLinkedTrack;
	lowLinkedTrack.setIcon(QMessageBox::Critical);
	lowLinkedTrack.setText("There needs to be 2 or more Linked tracks to connect! Number of Linked Track also has to be even!");
	lowLinkedTrack.exec();
}

void Message::showOddNumOfLinkedTrackErrorMessage()
{
	//Show oddNumOfLinkTrack error box.
	QMessageBox oddNumofLinkedTrack;
	oddNumofLinkedTrack.setIcon(QMessageBox::Critical);
	oddNumofLinkedTrack.setText("Cannot link track. Odd number of LinkedTrack");
	oddNumofLinkedTrack.exec();
}

void Message::showNotAllTrackConnectedErrorMessage()
{
	QMessageBox notConnectedBox;
	notConnectedBox.setIcon(QMessageBox::Critical);
	notConnectedBox.setText("Not all track connected");
	notConnectedBox.exec();
}

void Message::showZeroTrackErrorMessage()
{
	QMessageBox zeroTrackBox;
	zeroTrackBox.setIcon(QMessageBox::Critical);
	zeroTrackBox.setText("There are zero tracks stored.");
	zeroTrackBox.exec();
}

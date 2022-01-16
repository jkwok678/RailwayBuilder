#ifndef MESSAGE_H
#define MESSAGE_H

#include<QMessageBox>

class Message
{
public:
	Message();

	//Success

	/**
	 * @brief Show the user a scuess message saying all tracks are connected.
	 *
	 * Used in the Map class when checking if tracks are all connected.
	 */
	void showAllTrackConnecedSuccessMessage();

	//Confirmations



	//Errors

	/**
	 * @brief Shows the user an error message saying they cannot place an element on top of an existing element.
	 *
	 * Used in the Map class when placing elements.
	 */
	void showElementAlreadyThereErrorMessage();

	/**
	 * @brief A method that shows an error message if the user tries to connect Linked Tracks when there are none.
	 *
	 * Used in the Window class when connecting linkedTracks.
	 */
	void showLowNumOfLinkedTrackErrorMessage();

	/**
	 * @brief A method that shows an error message if the user tries to connect Linked Tracks when there is an odd number of them.
	 *
	 * Used in the Window class when connecting linkedTracks.
	 */
	void showOddNumOfLinkedTrackErrorMessage();

	/**
	 * @brief A method that shows an error message if the user hasn't got all tracks connected.
	 *
	 * Used in the Map class when checking if tracks are all connected.
	 */
	static void showNotAllTrackConnectedErrorMessage();

	/**
	 * @brief A method that shows an error message there are no tracks stored.
	 *
	 * Used in the Map class when checking if tracks are all connected.
	 */
	static void showZeroTrackErrorMessage();

};

#endif // MESSAGE_H

#ifndef ERRORMESSAGE_H
#define ERRORMESSAGE_H

#include<QMessageBox>

class ErrorMessage
{
public:
	ErrorMessage();

	/**
	 * @brief Shows the user an error message saying they cannot place an element on top of an existing element.
	 *
	 * Used in the Map class when placing elements.
	 */
	void showElementAlreadyThereError();

	/**
	 * @brief A method that shows an error message if the user tries to connect Linked Tracks when there are none.
	 *
	 * Used in the Window class when connecting linkedTracks.
	 */
	static void showLowNumOfLinkedTrackErrorMessage();

	/**
	 * @brief A method that shows an error message if the user tries to connect Linked Tracks when there is an odd number of them.
	 *
	 * Used in the Window class when connecting linkedTracks.
	 */
	static void showOddNumOfLinkedTrackErrorMessage();
};

#endif // ERRORMESSAGE_H

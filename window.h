#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QtCore>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QMenuBar>
#include <QLineEdit>
#include <QToolButton>
#include <QStatusBar>
#include <QLabel>
#include <QFontDialog>
#include <string>
#include <iostream>
#include <QSizePolicy>
#include "borderlayout.h"
#include "canvas.h"
#include "element.h"
#include "mode.h"
#include "elementChosen.h"




/**
 * @brief The Window class for making the entire GUI for the program.
 *
 * @author Jonathan Kwok
 * @version 0.1
 */
class Window : public QWidget
{
	Q_OBJECT

public:

	/**
	 * @brief A constructor for a Window object that extends the QWidget.
	 * Create a window object that includes the different parts needed to make the program function like the Canvas and the BorderLayout.
	 */
	Window();

	~Window();


	/**
	 * @brief The old method to convert distances. (Not used right now)
	 *
	 * This method will convert miles, chains and yards to metres first, then add them up.
	 * So if 2 other units of measurements are 0, it just converts the 1 unit of measurement that isn't 0.
	 * @return
	 */
	int convertDistances();

	/**
	 * @brief The new method to convert distances.
	 * @param miles The miles to convert as a double.
	 * @param chains The chains to convert as a double.
	 * @param yards The yards to convert as a double.
	 * @return The metres as a double.
	 */
	double convertDistances(double miles, double chains, double yards);

	/**
	 * @brief A method to convert speeds. (Not used right now)
	 *
	 * This method will convert Mph to Km/h and vice versa.
	 * @return
	 */
	int convertSpeed();

	/**
	 * @brief The new method to convert speed.
	 * @param speed The speed to convert as a double.
	 * @return The new speed after conversion as a double.
	 */
	double convertSpeed(double speed);

private slots:

	/**
	 * @brief A slot to open the element menu to place elements on screen.
	 */
	void openElementMenu();

	/**
	 * @brief A slot to open the SetSpeedDistance menu to set Track speed and length and to convert different types of measurements.
	 */
	void openSetConvertSpeedDistanceMenu();

	/**
	 * @brief A method to update the GUI for converting miles, chains and yards to metres.
	 */
	void updateMilesChainsYardsToMetresGUI();

	/**
	 * @brief A method to swap the labels so they make better sense when converting speed.
	 */
	void swapSpeedLabel();

	/**
	 * @brief A method to convert Mph to Km/h and vice versa.
	 */
	void updateMPHKMHGUI();

	//Element Menu choose Elements.

	/**
	 * @brief A slot to select StraightH tracks to place on screen.
	 */
	void chooseStraightH();

	//Right hand side menu.

	/**
	 * @brief A slot to move the canvas to the right.
	 */
	void moveRightOnCanvas();

	/**
	 * @brief A slot to move the canvas to the left.
	 */
	void moveLeftOnCanvas();

	/**
	 * @brief A slot to move the canvas upwards.
	 */
	void moveUpOnCanvas();

	/**
	 * @brief A slot to move the canvas downwards.
	 */
	void moveDownOnCanvas();

private:

	Canvas *drawingArea;
	//Menubar


	QMenuBar *menuBar;
	QMenu *fileMenu;
	QMenu *modeMenu;


	Mode mode;
	ElementChosen elementChosenToPlace;
	QWidget *top1Menu;

	QHBoxLayout *buildModifyMenu1;

	QToolButton *elementMenuButton;
	QIcon   *elementMenuIcon;
	QAction *openElementMenuAct;

	QToolButton *setConvertSpeedDistanceMenuButton;
	QIcon   *setConvertSpeedDistanceMenuIcon;
	QAction *openSetConvertSpeedDistanceMenuAct;

	QStackedWidget *allMenus;


	//Element menu


	QWidget *elementMenu;
	QGridLayout* elementMenuLayout;

	QToolButton *straightHButton;
	QIcon *straightHIcon;
	QAction *chooseStraightHAct;


	//SetConvertSpeedDistance menu


	QWidget *setConvertSpeedDistanceMenu;
	QHBoxLayout *setConvertSpeedDistanceHLayout;

	QLabel* keyGraphicImage;
	QImage* keyImage;

	QGridLayout* converterGrid1;
	QLabel* milesLabel;
	QLineEdit* milesEntry;
	QLabel* chainsLabel;
	QLineEdit* chainsEntry;
	QLabel* yardsLabel;
	QLineEdit* yardsEntry;
	QLabel* metresLabel;
	QLineEdit* actualMetres;
	const double MILE_FACTOR{1609.34};
	const double CHAIN_FACTOR{20.117};
	const double YARD_FACTOR{0.9144};


	QGridLayout* converterGrid2;
	QLabel* speedLabel1;
	QLineEdit* speedEntry1;
	QPushButton* swapLabelButton;
	QLabel* speedLabel2;
	QLineEdit* speedResult;
	bool mphToKmh{true};
	const double MPH_TO_KMPH{1.60934};


	//Right side directional Menu

	QWidget* rightDirectionalMenu;
	QVBoxLayout* rightDirectionalMenuLayout;

	QToolButton *canvasMoveRightButton;
	QIcon   *canvasMoveRightIcon;
	QAction *canvasMoveRightAct;

	QToolButton *canvasMoveLeftButton;
	QIcon   *canvasMoveLeftIcon;
	QAction *canvasMoveLeftAct;

	QToolButton *canvasMoveUpButton;
	QIcon   *canvasMoveUpIcon;
	QAction *canvasMoveUpAct;

	QToolButton *canvasMoveDownButton;
	QIcon   *canvasMoveDownIcon;
	QAction *canvasMoveDownAct;

	/**
	 * @brief A method to create the menubar that is at the top of the screen.
	 *
	 * Currently only addes a File and Mode menu.
	 * @version 0.1
	 */
	void createMenuBar();

	/**
	 * @brief A method to create the overall menu of the program.
	 */
	void createOverallMenu();

	/**
	 * @brief A method to create the menu that is shown after the Build/Modify Railway is pressed in the menubar.
	 */
	void createBuildModifyMenu();


	//Element menu


	/**
	 * @brief A method to create the menu where the user can choose track type.
	 */
	void createElementMenu();

	/**
	 * @brief A method to create the part 1 of the element buttons where the user can choose track type.
	 */
	void createElementBlock1();


	//SetConvertSpeedDistance menu


	/**
	 * @brief A method to create the menu to set and convert speed and distances.
	 */
	void createSetConvertSpeedDistanceMenu();

	/**
	 * @brief A method to retrieve the user's miles input.
	 * @return The user's miles input.
	 */
	double getMilesFromGUIToConvert();

	/**
	 * @brief A method to retrieve the user's chains input.
	 * @return The user's chains input.
	 */
	double getChainsFromGUIToConvert();

	/**
	 * @brief A method to retrieve the user's yards input.
	 * @return The user's yards input.
	 */
	double getYardsFromGUIToConvert();

	/**
	 * @brief A method to retrieve the user's speed input.
	 * @return The user's speed input.
	 */
	double getSpeedFromGUIToConvert();

	/**
	 * @brief A method to convert convert miles to metres.
	 * @param miles The number of miles as a double.
	 * @return A double that is the number of metres.
	 */
	double convertMilesToMetres(double miles);

	/**
	 * @brief A method to convert convert chains to metres.
	 * @param chains The number of chains as a double.
	 * @return A double that is the number of metres.
	 */
	double convertChainsToMetres(double chains);

	/**
	 * @brief A method to convert convert yards to metres.
	 * @param yards The number of yards as a double.
	 * @return A double that is the number of metres.
	 */
	double convertYardsToMetres(double yards);

	/**
	 * @brief A method to convert MPH to KMPH.
	 * @param mph The mph as a double.
	 * @return A double that is the kmph.
	 */
	double convertMPHToKMPH(double mph);

	/**
	 * @brief A method to convert KMPH to MPH.
	 * @param kmph The kmph as a double.
	 * @return A double that is the mph.
	 */
	double convertKMPHToMPH(double kmph);


	//Right side directional Menu


	/**
	 * @brief A method to make the right hand side menu.
	 */
	void createRightDirectionalMenu();
};
#endif // WINDOW_H

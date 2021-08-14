#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QtCore>
#include <QIcon>
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

	/**
	 * @brief A method to change the aspects of signal tracks added to screen.
	 */
	void changeAspect();

	//Element Menu choose Elements.

	//ElementBlock1 slots

	/**
	 * @brief A slot to select StraightH tracks to place on screen.
	 */
	void chooseStraightH();

	/**
	 * @brief A slot to select StraightV tracks to place on screen.
	 */
	void chooseStraightV();

	/**
	 * @brief A slot to select DirectedLeft tracks to place on screen.
	 */
	void chooseDirectedLeft();

	/**
	 * @brief A slot to select DirectedRight tracks to place on screen.
	 */
	void chooseDirectedRight();

	/**
	 * @brief A slot to select DirectedUp tracks to place on screen.
	 */
	void chooseDirectedUp();

	/**
	 * @brief A slot to select DirectedDown tracks to place on screen.
	 */
	void chooseDirectedDown();

	/**
	 * @brief A slot to select StraightLeftUp tracks to place on screen.
	 */
	void chooseStraightLeftUp();

	/**
	 * @brief A slot to select StraightRightUp tracks to place on screen.
	 */
	void chooseStraightRightUp();

	/**
	 * @brief A slot to select DirectedLeftUp tracks to place on screen.
	 */
	void chooseDirectedLeftUp();

	/**
	 * @brief A slot to select DirectedRightUp tracks to place on screen.
	 */
	void chooseDirectedRightUp();

	/**
	 * @brief A slot to select DirectedLeftDown tracks to place on screen.
	 */
	void chooseDirectedLeftDown();

	/**
	 * @brief A slot to select DirectedRightDown tracks to place on screen.
	 */
	void chooseDirectedRightDown();

	/**
	 * @brief A slot to select TightCurve1 tracks to place on screen.
	 */
	void chooseTightCurve1();

	/**
	 * @brief A slot to select TightCurve2 tracks to place on screen.
	 */
	void chooseTightCurve2();

	/**
	 * @brief A slot to select TightCurve3 tracks to place on screen.
	 */
	void chooseTightCurve3();

	/**
	 * @brief A slot to select TightCurve4 tracks to place on screen.
	 */
	void chooseTightCurve4();

	/**
	 * @brief A slot to select Curve1 tracks to place on screen.
	 */
	void chooseCurve1();

	/**
	 * @brief A slot to select Curve2 tracks to place on screen.
	 */
	void chooseCurve2();

	/**
	 * @brief A slot to select Curve3 tracks to place on screen.
	 */
	void chooseCurve3();

	/**
	 * @brief A slot to select Curve4 tracks to place on screen.
	 */
	void chooseCurve4();

	/**
	 * @brief A slot to select LinkLeft tracks to place on screen.
	 */
	void chooseLinkLeft();

	/**
	 * @brief A slot to select LinkRight tracks to place on screen.
	 */
	void chooseLinkRight();

	/**
	 * @brief A slot to select LinkDown tracks to place on screen.
	 */
	void chooseLinkDown();

	/**
	 * @brief A slot to select LinkUp tracks to place on screen.
	 */
	void chooseLinkUp();

	/**
	 * @brief A slot to select LinkLeftUp tracks to place on screen.
	 */
	void chooseLinkLeftUp();

	/**
	 * @brief A slot to select LinkRightUp tracks to place on screen.
	 */
	void chooseLinkRightUp();

	/**
	 * @brief A slot to select LinkLeftDown tracks to place on screen.
	 */
	void chooseLinkLeftDown();

	/**
	 * @brief A slot to select LinkRightDown tracks to place on screen.
	 */
	void chooseLinkRightDown();

	/**
	 * @brief A slot to select ExitLeft tracks to place on screen.
	 */
	void chooseExitLeft();

	/**
	 * @brief A slot to select ExitRight tracks to place on screen.
	 */
	void chooseExitRight();

	/**
	 * @brief A slot to select ExitDown tracks to place on screen.
	 */
	void chooseExitDown();

	/**
	 * @brief A slot to select ExitUp tracks to place on screen.
	 */
	void chooseExitUp();

	/**
	 * @brief A slot to select ExitLeftUp tracks to place on screen.
	 */
	void chooseExitLeftUp();

	/**
	 * @brief A slot to select ExitRightUp tracks to place on screen.
	 */
	void chooseExitRightUp();

	/**
	 * @brief A slot to select ExitLeftDown tracks to place on screen.
	 */
	void chooseExitLeftDown();

	/**
	 * @brief A slot to select ExitRightDown tracks to place on screen.
	 */
	void chooseExitRightDown();

	/**
	 * @brief A slot to select Curve5 tracks to place on screen.
	 */
	void chooseCurve5();

	/**
	 * @brief A slot to select Curve6 tracks to place on screen.
	 */
	void chooseCurve6();

	/**
	 * @brief A slot to select Curve7 tracks to place on screen.
	 */
	void chooseCurve7();

	/**
	 * @brief A slot to select Curve8 tracks to place on screen.
	 */
	void chooseCurve8();

	/**
	 * @brief A slot to select BufferLeft tracks to place on screen.
	 */
	void chooseBufferLeft();

	/**
	 * @brief A slot to select BufferRight tracks to place on screen.
	 */
	void chooseBufferRight();

	/**
	 * @brief A slot to select BufferDown tracks to place on screen.
	 */
	void chooseBufferDown();

	/**
	 * @brief A slot to select BufferUp tracks to place on screen.
	 */
	void chooseBufferUp();

	/**
	 * @brief A slot to select BufferLeftUp tracks to place on screen.
	 */
	void chooseBufferLeftUp();

	/**
	 * @brief A slot to select BufferRightUp tracks to place on screen.
	 */
	void chooseBufferRightUp();

	/**
	 * @brief A slot to select BufferLeftDown tracks to place on screen.
	 */
	void chooseBufferLeftDown();

	/**
	 * @brief A slot to select BufferRightDown tracks to place on screen.
	 */
	void chooseBufferRightDown();

	/**
	 * @brief A slot to select SignalLeft tracks to place on screen.
	 */
	void chooseSignalLeft();

	/**
	 * @brief A slot to select SignalRight tracks to place on screen.
	 */
	void chooseSignalRight();

	/**
	 * @brief A slot to select SignalDown tracks to place on screen.
	 */
	void chooseSignalDown();

	/**
	 * @brief A slot to select SignalUp tracks to place on screen.
	 */
	void chooseSignalUp();

	/**
	 * @brief A slot to select SignalLeftUp tracks to place on screen.
	 */
	void chooseSignalLeftUp();

	/**
	 * @brief A slot to select SignalRightUp tracks to place on screen.
	 */
	void chooseSignalRightUp();

	/**
	 * @brief A slot to select SignalLeftDown tracks to place on screen.
	 */
	void chooseSignalLeftDown();

	/**
	 * @brief A slot to select SignalRightDown tracks to place on screen.
	 */
	void chooseSignalRightDown();

	/**
	 * @brief A slot to select Bridge1 tracks to place on screen.
	 */
	void chooseBridge1();

	/**
	 * @brief A slot to select Bridge2 tracks to place on screen.
	 */
	void chooseBridge2();

	/**
	 * @brief A slot to select Underpass1 tracks to place on screen.
	 */
	void chooseUnderpass1();

	/**
	 * @brief A slot to select Underpass2 tracks to place on screen.
	 */
	void chooseUnderpass2();

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



	ElementChosen elementChosenToPlace;
	QWidget *top1Menu;

	QHBoxLayout *buildModifyMenu1;

	QToolButton *elementMenuButton;
	QIcon   *elementMenuIcon;
	QAction *openElementMenuAct;

	QToolButton *setConvertSpeedDistanceMenuButton;
	QIcon   *setConvertSpeedDistanceMenuIcon;
	QAction *openSetConvertSpeedDistanceMenuAct;

	QToolButton *setAspectButton;
	QIcon* aspect4Icon;
	QIcon* aspect3Icon;
	QIcon* aspect2Icon;
	QIcon* aspectShuntIcon;
	QAction *changeAspectAct;

	QStackedWidget *allMenus;


	//Element menu


	QWidget *elementMenu;
	QGridLayout* elementMenuLayout;

	QToolButton *straightHButton;
	QIcon *straightHIcon;
	QAction *chooseStraightHAct;

	//ElementBlock1 buttons

	//StraightVButton
	QToolButton* straightVButton;
	QAction* chooseStraightVAct;
	QIcon* straightVIcon;

	//DirectedLeftButton
	QToolButton* directedLeftButton;
	QAction* chooseDirectedLeftAct;
	QIcon* directedLeftIcon;

	//DirectedRightButton
	QToolButton* directedRightButton;
	QAction* chooseDirectedRightAct;
	QIcon* directedRightIcon;

	//DirectedUpButton
	QToolButton* directedUpButton;
	QAction* chooseDirectedUpAct;
	QIcon* directedUpIcon;

	//DirectedDownButton
	QToolButton* directedDownButton;
	QAction* chooseDirectedDownAct;
	QIcon* directedDownIcon;

	//StraightLeftUpButton
	QToolButton* straightLeftUpButton;
	QAction* chooseStraightLeftUpAct;
	QIcon* straightLeftUpIcon;

	//StraightRightUpButton
	QToolButton* straightRightUpButton;
	QAction* chooseStraightRightUpAct;
	QIcon* straightRightUpIcon;

	//DirectedLeftUpButton
	QToolButton* directedLeftUpButton;
	QAction* chooseDirectedLeftUpAct;
	QIcon* directedLeftUpIcon;

	//DirectedRightUpButton
	QToolButton* directedRightUpButton;
	QAction* chooseDirectedRightUpAct;
	QIcon* directedRightUpIcon;

	//DirectedLeftDownButton
	QToolButton* directedLeftDownButton;
	QAction* chooseDirectedLeftDownAct;
	QIcon* directedLeftDownIcon;

	//DirectRightDownButton
	QToolButton* directedRightDownButton;
	QAction* chooseDirectedRightDownAct;
	QIcon* directedRightDownIcon;

	//TightCurve1Button
	QToolButton* tightCurve1Button;
	QAction* chooseTightCurve1Act;
	QIcon* tightCurve1Icon;

	//TightCurve2Button
	QToolButton* tightCurve2Button;
	QAction* chooseTightCurve2Act;
	QIcon* tightCurve2Icon;

	//TightCurve3Button
	QToolButton* tightCurve3Button;
	QAction* chooseTightCurve3Act;
	QIcon* tightCurve3Icon;

	//Tightcurve4Button
	QToolButton* tightCurve4Button;
	QAction* chooseTightCurve4Act;
	QIcon* tightCurve4Icon;

	//Curve1Button
	QToolButton* curve1Button;
	QAction* chooseCurve1Act;
	QIcon* curve1Icon;

	//Curve2Button
	QToolButton* curve2Button;
	QAction* chooseCurve2Act;
	QIcon* curve2Icon;

	//Curve3Button
	QToolButton* curve3Button;
	QAction* chooseCurve3Act;
	QIcon* curve3Icon;

	//Curve4Button
	QToolButton* curve4Button;
	QAction* chooseCurve4Act;
	QIcon* curve4Icon;

	//LinkLeftButton
	QToolButton* linkLeftButton;
	QAction* chooseLinkLeftAct;
	QIcon* linkLeftIcon;

	//LinkRightButton
	QToolButton* linkRightButton;
	QAction* chooseLinkRightAct;
	QIcon* linkRightIcon;

	//LinkDownButton
	QToolButton* linkDownButton;
	QAction* chooseLinkDownAct;
	QIcon* linkDownIcon;

	//LinkUpButton
	QToolButton* linkUpButton;
	QAction* chooseLinkUpAct;
	QIcon* linkUpIcon;

	//LinkLeftUpButton
	QToolButton* linkLeftUpButton;
	QAction* chooseLinkLeftUpAct;
	QIcon* linkLeftUpIcon;

	//LinkRightUpButton
	QToolButton* linkRightUpButton;
	QAction* chooseLinkRightUpAct;
	QIcon* linkRightUpIcon;

	//LinkLeftDownButton
	QToolButton* linkLeftDownButton;
	QAction* chooseLinkLeftDownAct;
	QIcon* linkLeftDownIcon;

	//LinkRightDownButton
	QToolButton* linkRightDownButton;
	QAction* chooseLinkRightDownAct;
	QIcon* linkRightDownIcon;

	//ExitLeftButton
	QToolButton* exitLeftButton;
	QAction* chooseExitLeftAct;
	QIcon* exitLeftIcon;

	//ExitRightButton
	QToolButton* exitRightButton;
	QAction* chooseExitRightAct;
	QIcon* exitRightIcon;

	//ExitDownButton
	QToolButton* exitDownButton;
	QAction* chooseExitDownAct;
	QIcon* exitDownIcon;

	//ExitUpButton
	QToolButton* exitUpButton;
	QAction* chooseExitUpAct;
	QIcon* exitUpIcon;

	//ExitLeftUpButton
	QToolButton* exitLeftUpButton;
	QAction* chooseExitLeftUpAct;
	QIcon* exitLeftUpIcon;

	//ExitRightUpButton
	QToolButton* exitRightUpButton;
	QAction* chooseExitRightUpAct;
	QIcon* exitRightUpIcon;

	//ExitLeftDownButton
	QToolButton* exitLeftDownButton;
	QAction* chooseExitLeftDownAct;
	QIcon* exitLeftDownIcon;

	//ExitRightDownButton
	QToolButton* exitRightDownButton;
	QAction* chooseExitRightDownAct;
	QIcon* exitRightDownIcon;

	//Curve5Button
	QToolButton* curve5Button;
	QAction* chooseCurve5Act;
	QIcon* curve5Icon;

	//Curve6Button
	QToolButton* curve6Button;
	QAction* chooseCurve6Act;
	QIcon* curve6Icon;

	//Curve7Button
	QToolButton* curve7Button;
	QAction* chooseCurve7Act;
	QIcon* curve7Icon;

	//Curve8Button
	QToolButton* curve8Button;
	QAction* chooseCurve8Act;
	QIcon* curve8Icon;

	//BufferLeftButton
	QToolButton* bufferLeftButton;
	QAction* chooseBufferLeftAct;
	QIcon* bufferLeftIcon;

	//BufferRightButton
	QToolButton* bufferRightButton;
	QAction* chooseBufferRightAct;
	QIcon* bufferRightIcon;

	//BufferDownButton
	QToolButton* bufferDownButton;
	QAction* chooseBufferDownAct;
	QIcon* bufferDownIcon;

	//BufferUpButton
	QToolButton* bufferUpButton;
	QAction* chooseBufferUpAct;
	QIcon* bufferUpIcon;

	//BufferLeftUpButton
	QToolButton* bufferLeftUpButton;
	QAction* chooseBufferLeftUpAct;
	QIcon* bufferLeftUpIcon;

	//BufferRightUpButton
	QToolButton* bufferRightUpButton;
	QAction* chooseBufferRightUpAct;
	QIcon* bufferRightUpIcon;

	//BufferLeftDownButton
	QToolButton* bufferLeftDownButton;
	QAction* chooseBufferLeftDownAct;
	QIcon* bufferLeftDownIcon;

	//BufferRightDownButton
	QToolButton* bufferRightDownButton;
	QAction* chooseBufferRightDownAct;
	QIcon* bufferRightDownIcon;

	//SignalLeftButton
	QToolButton* signalLeftButton;
	QAction* chooseSignalLeftAct;
	QIcon* signalLeftIcon;
	QIcon* shuntLeftIcon;

	//SignalRightButton
	QToolButton* signalRightButton;
	QAction* chooseSignalRightAct;
	QIcon* signalRightIcon;
	QIcon* shuntRightIcon;

	//SignalDownButton
	QToolButton* signalDownButton;
	QAction* chooseSignalDownAct;
	QIcon* signalDownIcon;
	QIcon* shuntDownIcon;

	//SignalUpButton
	QToolButton* signalUpButton;
	QAction* chooseSignalUpAct;
	QIcon* signalUpIcon;
	QIcon* shuntUpIcon;

	//SignalLeftUpButton
	QToolButton* signalLeftUpButton;
	QAction* chooseSignalLeftUpAct;
	QIcon* signalLeftUpIcon;
	QIcon* shuntLeftUpIcon;

	//SignalRightUpButton
	QToolButton* signalRightUpButton;
	QAction* chooseSignalRightUpAct;
	QIcon* signalRightUpIcon;
	QIcon* shuntRightUpIcon;

	//SignalLeftDownButton
	QToolButton* signalLeftDownButton;
	QAction* chooseSignalLeftDownAct;
	QIcon* signalLeftDownIcon;
	QIcon* shuntLeftDownIcon;

	//SignalRightDownButton
	QToolButton* signalRightDownButton;
	QAction* chooseSignalRightDownAct;
	QIcon* signalRightDownIcon;
	QIcon* shuntRightDownIcon;

	//Bridge2Button
	QToolButton* bridge1Button;
	QAction* chooseBridge1Act;;
	QIcon* bridge1Icon;

	//Bridge2Button
	QToolButton* bridge2Button;
	QAction* chooseBridge2Act;
	QIcon* bridge2Icon;

	//Underpass1Button
	QToolButton* underpass1Button;
	QAction* chooseUnderpass1Act;;
	QIcon* underpass1Icon;

	//Underpass2Button
	QToolButton* underpass2Button;
	QAction* chooseUnderpass2Act;
	QIcon* underpass2Icon;


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

#include "window.h"

//Public

Window::Window()
{
	drawingArea = new Canvas;
	createMenuBar();
	createOverallMenu();
	createRightDirectionalMenu();
	BorderLayout *layout = new BorderLayout;
	layout->addWidget(menuBar,BorderLayout::North);
	layout->addWidget(top1Menu,BorderLayout::North);
	layout->addWidget(allMenus,BorderLayout::North);
	layout->addWidget(drawingArea, BorderLayout::Center);
	layout->addWidget(rightDirectionalMenu, BorderLayout::East);
	setLayout(layout);
}

Window::~Window()
{

}

int Window::convertDistances()
{
	/* If the miles text entry isn't empty, try make it a double.
	 * Then make it equal to the double that was inputted by the user.
	 * Otherwise make miles = 0.
	 */
	double miles,chains,yards;
	if (!milesEntry->text().isEmpty())
	{
		bool ok = false;
		double tempD = milesEntry->text().toDouble(&ok);
		if (ok)
		{
			 miles = tempD;
		}
	}
	else
	{
		miles = 0;
	}

	/* If the chains text entry isn't empty, try make it a double.
	 * Then make it equal to the double that was inputted by the user.
	 * Otherwise make chains = 0.
	 */
	if (!chainsEntry->text().isEmpty())
	{
		bool ok = false;
		double tempD = chainsEntry->text().toDouble(&ok);
		if (ok)
		{
			 chains = tempD;
		}
	}
	else
	{
		chains = 0;
	}
	/* If the yards text entry isn't empty, try make it a double.
	 * Then make it equal to the double that was inputted by the user.
	 * Otherwise make yards = 0.
	 */
	if (!yardsEntry->text().isEmpty())
	{
		bool ok = false;
		double tempD = yardsEntry->text().toDouble(&ok);
		if (ok)
		{
			 yards = tempD;
		}
	}
	else
	{
		yards = 0;
	}
	//Calculate miles + chains + yards in metres.
	int metres = round((miles* MILE_FACTOR) +(chains* CHAIN_FACTOR) + (yards* YARD_FACTOR));
	metres = std::ceil(metres * 100.0) / 100.0;
	return metres;
}

double Window::convertDistances(double miles, double chains, double yards)
{
	double resultM = convertMilesToMetres(miles);
	double resultC = convertChainsToMetres(chains);
	double resultY = convertYardsToMetres(yards);
	double metres = resultM + resultC + resultY;
	//* 100.0) / 100.0;
	return metres;
}

int Window::convertSpeed()
{
	//Convert mph to kmh or vice versa
	double result;
	double temp;
	//If a speed is entered, try convert it to a double.
	bool ok = false;
	double tempD = speedEntry1->text().toDouble(&ok);
	if (ok)
	{
		temp = tempD;
	}
	if (mphToKmh)
	{
		result = temp * MPH_TO_KMPH;
	}
	else
	{
		result = temp / MPH_TO_KMPH;
	}
	//Round up the result and display it.
	result = std::round(result * 100.0) / 100.0;
	return result;

}

double Window::convertSpeed(double speed)
{
	//Convert mph to kmh or vice versa
	double result;
	if (mphToKmh)
	{
		result = convertMPHToKMPH(speed);
	}
	else
	{
		result = convertKMPHToMPH(speed);
	}
	//Round up the result.
	result = std::ceil(result * 100.0) / 100.0;
	return result;
}


//private slots

void Window::canvasToWhite()
{
	drawingArea->setCanvasColour(Qt::white);
	drawingArea->canvasChangeColour();
	drawingArea->trackChangeColour();
}

void Window::canvasToDarkBlue()
{
	drawingArea->setCanvasColour(Qt::darkBlue);
	drawingArea->canvasChangeColour();
	drawingArea->trackChangeColour();
}

void Window::canvasToBlack()
{
	drawingArea->setCanvasColour(Qt::black);
	drawingArea->canvasChangeColour();
	drawingArea->trackChangeColour();
}


void Window::openElementMenu()
{
	//Set the QStackWidget to the AddMoveTrack menu if it isn't on there yet.
	//If it is, then go back to the start.
	if (allMenus->currentIndex() != 1 && drawingArea->getMode() != Mode::ADDREMOVETRACK)
	{
		allMenus->setCurrentIndex(1);
		drawingArea->setMode(Mode::ADDREMOVETRACK);
	}
	else
	{
		allMenus->setCurrentIndex(0);
		drawingArea->setMode(Mode::NONE);
	}

}

void Window::openSetConvertSpeedDistanceMenu()
{
	//Set the QStackWidget to the setConvertSpeedDistance menu if it isn't on there yet.
	//If it is, then go back to the start.
	if (allMenus->currentIndex() != 2 && drawingArea->getMode() != Mode::SETCONVERTSPEEDDISTANCE)
	{
		allMenus->setCurrentIndex(2);
		drawingArea->setMode(Mode::SETCONVERTSPEEDDISTANCE);
	}
	else
	{
		allMenus->setCurrentIndex(0);
		drawingArea->setMode(Mode::NONE);
	}
}

void Window::updateMilesChainsYardsToMetresGUI()
{

	//Display it to user
	double miles = getMilesFromGUIToConvert();
	double chains = getChainsFromGUIToConvert();
	double yards = getYardsFromGUIToConvert();
	double metres = convertDistances(miles,chains,yards);
	actualMetres->setText(QString::number(metres));
}

void Window::swapSpeedLabel()
{
	//Swap the 2 texts on the labels
	//Then reconvert the numbers
	QString temp = speedLabel1->text();
	speedLabel1->setText(speedLabel2->text());
	speedLabel2->setText(temp);
	if (mphToKmh)
	{
		mphToKmh = false;
	}
	else
	{
		mphToKmh = true;
	}
	updateMPHKMHGUI();
}

void Window::updateMPHKMHGUI()
{
	double speed = getSpeedFromGUIToConvert();
	int result = convertSpeed(speed);
	if (!speedEntry1->text().isEmpty())
	{
		speedResult->setText(QString::number(result));
	}
	else
	{
		speedResult->setText("");
	}

}

void Window::changeAspect()
{
	//Change aspect from 4 -> 3 -> 2 -> 1 then back to 4.
	//Also change button icons along the way.
	if (drawingArea->getSignalAspectToAdd() == 4)
	{
		drawingArea->setSignalAspectToAdd(3);

		setAspectButton->setIcon(*aspect3Icon);
	}
	else if (drawingArea->getSignalAspectToAdd() == 3)
	{
		drawingArea->setSignalAspectToAdd(2);
		setAspectButton->setIcon(*aspect2Icon);
	}
	else if (drawingArea->getSignalAspectToAdd() == 2)
	{
		drawingArea->setSignalAspectToAdd(1);
		setAspectButton->setIcon(*aspectShuntIcon);
		signalLeftButton->setIcon(*shuntLeftIcon);
		signalRightButton->setIcon(*shuntRightIcon);
		signalDownButton->setIcon(*shuntDownIcon);
		signalUpButton->setIcon(*shuntUpIcon);
		signalLeftUpButton->setIcon(*shuntLeftUpIcon);
		signalRightUpButton->setIcon(*shuntRightUpIcon);
		signalLeftDownButton->setIcon(*shuntLeftDownIcon);
		signalRightDownButton->setIcon(*shuntRightDownIcon);
	}
	else if (drawingArea->getSignalAspectToAdd() ==1)
	{
		drawingArea->setSignalAspectToAdd(4);
		setAspectButton->setIcon(*aspect4Icon);
		signalLeftButton->setIcon(*signalLeftIcon);
		signalRightButton->setIcon(*signalRightIcon);
		signalDownButton->setIcon(*signalDownIcon);
		signalUpButton->setIcon(*signalUpIcon);
		signalLeftUpButton->setIcon(*signalLeftUpIcon);
		signalRightUpButton->setIcon(*signalRightUpIcon);
		signalLeftDownButton->setIcon(*signalLeftDownIcon);
		signalRightDownButton->setIcon(*signalRightDownIcon);
	}
}

//Element menu to choose element

//Element block 1 slots.

void Window::chooseStraightH()
{
	//If the Mode is AddRemoveTrack and the element is StraightH,
	// the element to add will be a Straight horizontal.
	//Otherwise set to nothing.
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::STRAIGHTH)
	{
		drawingArea->setElementChosen(ElementChosen::STRAIGHTH);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseStraightV()
{
	//If the Mode is AddRemoveTrack and the element is StraightV,
	// the element to add will be a Straight vertical.
	//Otherwise set to nothing.
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::STRAIGHTV)
	{
		drawingArea->setElementChosen(ElementChosen::STRAIGHTV);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseDirectedLeft()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::DIRECTEDLEFT)
	{
		drawingArea->setElementChosen(ElementChosen::DIRECTEDLEFT);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseDirectedRight()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::DIRECTEDRIGHT)
	{
		drawingArea->setElementChosen(ElementChosen::DIRECTEDRIGHT);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseDirectedUp()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::DIRECTEDUP)
	{
		drawingArea->setElementChosen(ElementChosen::DIRECTEDUP);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseDirectedDown()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::DIRECTEDDOWN)
	{
		drawingArea->setElementChosen(ElementChosen::DIRECTEDDOWN);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseStraightLeftUp()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::STRAIGHTLEFTUP)
	{
		drawingArea->setElementChosen(ElementChosen::STRAIGHTLEFTUP);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseStraightRightUp()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::STRAIGHTRIGHTUP)
	{
		drawingArea->setElementChosen(ElementChosen::STRAIGHTRIGHTUP);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseDirectedLeftUp()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::DIRECTEDLEFTUP)
	{
		drawingArea->setElementChosen(ElementChosen::DIRECTEDLEFTUP);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseDirectedRightUp()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::DIRECTEDRIGHTUP)
	{
		drawingArea->setElementChosen(ElementChosen::DIRECTEDRIGHTUP);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseDirectedLeftDown()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::DIRECTEDLEFTDOWN)
	{
		drawingArea->setElementChosen(ElementChosen::DIRECTEDLEFTDOWN);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseDirectedRightDown()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::DIRECTEDRIGHTDOWN)
	{
		drawingArea->setElementChosen(ElementChosen::DIRECTEDRIGHTDOWN);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseTightCurve1()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::TIGHTCURVE1)
	{
		drawingArea->setElementChosen(ElementChosen::TIGHTCURVE1);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseTightCurve2()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::TIGHTCURVE2)
	{
		drawingArea->setElementChosen(ElementChosen::TIGHTCURVE2);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseTightCurve3()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::TIGHTCURVE3)
	{
		drawingArea->setElementChosen(ElementChosen::TIGHTCURVE3);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseTightCurve4()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::TIGHTCURVE4)
	{
		drawingArea->setElementChosen(ElementChosen::TIGHTCURVE4);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseCurve1()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CURVE1)
	{
		drawingArea->setElementChosen(ElementChosen::CURVE1);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseCurve2()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CURVE2)
	{
		drawingArea->setElementChosen(ElementChosen::CURVE2);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseCurve3()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CURVE3)
	{
		drawingArea->setElementChosen(ElementChosen::CURVE3);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseCurve4()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CURVE4)
	{
		drawingArea->setElementChosen(ElementChosen::CURVE4);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseLinkLeft()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::LINKLEFT)
	{
		drawingArea->setElementChosen(ElementChosen::LINKLEFT);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseLinkRight()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::LINKRIGHT)
	{
		drawingArea->setElementChosen(ElementChosen::LINKRIGHT);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseLinkDown()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::LINKDOWN)
	{
		drawingArea->setElementChosen(ElementChosen::LINKDOWN);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseLinkUp()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::LINKUP)
	{
		drawingArea->setElementChosen(ElementChosen::LINKUP);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseLinkLeftUp()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::LINKLEFTUP)
	{
		drawingArea->setElementChosen(ElementChosen::LINKLEFTUP);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseLinkRightUp()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::LINKRIGHTUP)
	{
		drawingArea->setElementChosen(ElementChosen::LINKRIGHTUP);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseLinkLeftDown()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::LINKLEFTDOWN)
	{
		drawingArea->setElementChosen(ElementChosen::LINKLEFTDOWN);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseLinkRightDown()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::LINKRIGHTDOWN)
	{
		drawingArea->setElementChosen(ElementChosen::LINKRIGHTDOWN);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseExitLeft()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::EXITLEFT)
	{
		drawingArea->setElementChosen(ElementChosen::EXITLEFT);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseExitRight()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::EXITRIGHT)
	{
		drawingArea->setElementChosen(ElementChosen::EXITRIGHT);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseExitDown()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::EXITDOWN)
	{
		drawingArea->setElementChosen(ElementChosen::EXITDOWN);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseExitUp()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::EXITUP)
	{
		drawingArea->setElementChosen(ElementChosen::EXITUP);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseExitLeftUp()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::EXITLEFTUP)
	{
		drawingArea->setElementChosen(ElementChosen::EXITLEFTUP);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseExitRightUp()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::EXITRIGHT)
	{
		drawingArea->setElementChosen(ElementChosen::EXITRIGHT);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseExitLeftDown()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::EXITLEFTDOWN)
	{
		drawingArea->setElementChosen(ElementChosen::EXITLEFTDOWN);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseExitRightDown()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::EXITRIGHTDOWN)
	{
		drawingArea->setElementChosen(ElementChosen::EXITRIGHTDOWN);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseCurve5()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CURVE5)
	{
		drawingArea->setElementChosen(ElementChosen::CURVE5);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseCurve6()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CURVE6)
	{
		drawingArea->setElementChosen(ElementChosen::CURVE6);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseCurve7()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CURVE7)
	{
		drawingArea->setElementChosen(ElementChosen::CURVE7);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseCurve8()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CURVE8)
	{
		drawingArea->setElementChosen(ElementChosen::CURVE8);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseBufferLeft()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BUFFERLEFT)
	{
		drawingArea->setElementChosen(ElementChosen::BUFFERLEFT);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseBufferRight()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BUFFERRIGHT)
	{
		drawingArea->setElementChosen(ElementChosen::BUFFERRIGHT);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseBufferDown()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BUFFERDOWN)
	{
		drawingArea->setElementChosen(ElementChosen::BUFFERDOWN);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseBufferUp()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BUFFERUP)
	{
		drawingArea->setElementChosen(ElementChosen::BUFFERUP);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseBufferLeftUp()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BUFFERLEFTUP)
	{
		drawingArea->setElementChosen(ElementChosen::BUFFERLEFTUP);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseBufferRightUp()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BUFFERRIGHTUP)
	{
		drawingArea->setElementChosen(ElementChosen::BUFFERRIGHTUP);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseBufferLeftDown()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BUFFERLEFTDOWN)
	{
		drawingArea->setElementChosen(ElementChosen::BUFFERLEFTDOWN);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseBufferRightDown()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BUFFERRIGHTDOWN)
	{
		drawingArea->setElementChosen(ElementChosen::BUFFERRIGHTDOWN);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSignalLeft()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SIGNALLEFT)
	{
		drawingArea->setElementChosen(ElementChosen::SIGNALLEFT);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSignalRight()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SIGNALRIGHT)
	{
		drawingArea->setElementChosen(ElementChosen::SIGNALRIGHT);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSignalDown()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SIGNALDOWN)
	{
		drawingArea->setElementChosen(ElementChosen::SIGNALDOWN);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSignalUp()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SIGNALUP)
	{
		drawingArea->setElementChosen(ElementChosen::SIGNALUP);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSignalLeftUp()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SIGNALLEFTUP)
	{
		drawingArea->setElementChosen(ElementChosen::SIGNALLEFTUP);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSignalRightUp()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SIGNALRIGHTUP)
	{
		drawingArea->setElementChosen(ElementChosen::SIGNALRIGHTUP);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSignalLeftDown()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SIGNALLEFTDOWN)
	{
		drawingArea->setElementChosen(ElementChosen::SIGNALLEFTDOWN);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSignalRightDown()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SIGNALRIGHTDOWN)
	{
		drawingArea->setElementChosen(ElementChosen::SIGNALRIGHTDOWN);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseBridge1()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BRIDGE1)
	{
		drawingArea->setElementChosen(ElementChosen::BRIDGE1);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseBridge2()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BRIDGE2)
	{
		drawingArea->setElementChosen(ElementChosen::BRIDGE2);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseUnderpass1()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::UNDERPASS1)
	{
		drawingArea->setElementChosen(ElementChosen::UNDERPASS1);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseUnderpass2()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::UNDERPASS2)
	{
		drawingArea->setElementChosen(ElementChosen::UNDERPASS2);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

//Element block 2 slots.

void Window::chooseSwitchTight1()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCHTIGHT1)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCHTIGHT1);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitchTight2()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCHTIGHT2)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCHTIGHT2);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitchTight3()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCHTIGHT3)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCHTIGHT3);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitchTight4()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCHTIGHT4)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCHTIGHT4);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitchTight5()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCHTIGHT5)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCHTIGHT5);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}

}

void Window::chooseSwitchTight6()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCHTIGHT6)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCHTIGHT6);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitchTight7()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCHTIGHT7)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCHTIGHT7);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitchTight8()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCHTIGHT8)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCHTIGHT8);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitchSplit1()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCHSPLIT1)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCHSPLIT1);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitchSplit2()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCHSPLIT2)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCHSPLIT2);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitchSplit3()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCHSPLIT3)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCHSPLIT3);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitch1()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCH1)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCH1);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitch2()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCH2)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCH2);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitch3()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCH3)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCH3);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitch4()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCH4)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCH4);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitch5()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCH5)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCH5);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitch6()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCH6)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCH6);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitch7()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCH7)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCH7);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitch8()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCH8)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCH8);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitchSplit4()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCHSPLIT4)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCHSPLIT4);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitchSplit5()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCHSPLIT5)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCHSPLIT5);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitchSplit6()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCHSPLIT6)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCHSPLIT6);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitch9()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCH9)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCH9);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitch10()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCH10)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCH10);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitch11()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCH11)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCH11);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitch12()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCH12)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCH12);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitch13()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCH13)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCH13);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitch14()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCH14)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCH14);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitch15()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCH15)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCH15);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitch16()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCH16)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCH16);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitchSplit7()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCHSPLIT7)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCHSPLIT7);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseSwitchSplit8()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SWITCHSPLIT8)
	{
		drawingArea->setElementChosen(ElementChosen::SWITCHSPLIT8);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

//Element block 3 slots.

void Window::chooseCrossover1()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CROSSOVER1)
	{
		drawingArea->setElementChosen(ElementChosen::CROSSOVER1);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseCrossover2()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CROSSOVER2)
	{
		drawingArea->setElementChosen(ElementChosen::CROSSOVER2);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseFlyover1()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::FLYOVER1)
	{
		drawingArea->setElementChosen(ElementChosen::FLYOVER1);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseFlyover2()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::FLYOVER2)
	{
		drawingArea->setElementChosen(ElementChosen::FLYOVER2);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseFlyover3()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::FLYOVER3)
	{
		drawingArea->setElementChosen(ElementChosen::FLYOVER3);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseFlyover4()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::FLYOVER4)
	{
		drawingArea->setElementChosen(ElementChosen::FLYOVER4);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseCrossover3()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CROSSOVER3)
	{
		drawingArea->setElementChosen(ElementChosen::CROSSOVER3);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseCrossover4()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CROSSOVER4)
	{
		drawingArea->setElementChosen(ElementChosen::CROSSOVER4);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseFlyover5()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::FLYOVER5)
	{
		drawingArea->setElementChosen(ElementChosen::FLYOVER5);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseFlyover6()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::FLYOVER6)
	{
		drawingArea->setElementChosen(ElementChosen::FLYOVER6);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseFlyover7()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::FLYOVER7)
	{
		drawingArea->setElementChosen(ElementChosen::FLYOVER7);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseFlyover8()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::FLYOVER8)
	{
		drawingArea->setElementChosen(ElementChosen::FLYOVER8);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseCrossover5()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CROSSOVER5)
	{
		drawingArea->setElementChosen(ElementChosen::CROSSOVER5);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseCrossover6()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CROSSOVER6)
	{
		drawingArea->setElementChosen(ElementChosen::CROSSOVER6);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseFlyover9()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::FLYOVER9)
	{
		drawingArea->setElementChosen(ElementChosen::FLYOVER9);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseFlyover10()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::FLYOVER10)
	{
		drawingArea->setElementChosen(ElementChosen::FLYOVER10);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseFlyover11()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::FLYOVER11)
	{
		drawingArea->setElementChosen(ElementChosen::FLYOVER11);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseFlyover12()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::FLYOVER12)
	{
		drawingArea->setElementChosen(ElementChosen::FLYOVER12);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

//Element block 4 slots.

void Window::chooseNamedLocation()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::NAMEDLOCATION)
	{
		drawingArea->setElementChosen(ElementChosen::NAMEDLOCATION);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseConcourse()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CONCOURSE)
	{
		drawingArea->setElementChosen(ElementChosen::CONCOURSE);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::choosePlatformLeft()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PLATFORMLEFT)
	{
		drawingArea->setElementChosen(ElementChosen::PLATFORMLEFT);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::choosePlatformRight()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PLATFORMRIGHT)
	{
		drawingArea->setElementChosen(ElementChosen::PLATFORMRIGHT);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::choosePlatformDown()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PLATFORMDOWN)
	{
		drawingArea->setElementChosen(ElementChosen::PLATFORMDOWN);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::choosePlatformUp()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PLATFORMUP)
	{
		drawingArea->setElementChosen(ElementChosen::PLATFORMUP);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

//Element block 5 slots.

void Window::chooseParapet1()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET1)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET1);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet2()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET2)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET2);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet3()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET3)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET3);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet4()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET4)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET4);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet5()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET5)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET5);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet6()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET6)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET6);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet7()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET7)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET7);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet8()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET8)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET8);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet9()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET9)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET9);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet10()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET10)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET10);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet11()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET11)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET11);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet12()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET12)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET12);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet13()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET13)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET13);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet14()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET14)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET14);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet15()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET15)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET15);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet16()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET16)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET16);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet17()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET17)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET17);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet18()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET18)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET18);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet19()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET19)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET19);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet20()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET20)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET20);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet21()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET21)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET21);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet22()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET22)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET22);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet23()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET23)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET23);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet24()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET24)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET24);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet25()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET25)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET25);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet26()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET26)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET26);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet27()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET27)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET27);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

void Window::chooseParapet28()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::PARAPET28)
	{
		drawingArea->setElementChosen(ElementChosen::PARAPET28);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

//Element block 6 slots.

void Window::chooseLevelCrossing()
{
	if (drawingArea->getMode() == Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::LEVELCROSSING)
	{
		drawingArea->setElementChosen(ElementChosen::LEVELCROSSING);
	}
	else
	{
		drawingArea->setElementChosen(ElementChosen::NONE);
	}
}

//Right hand side menu.

void Window::moveRightOnCanvas()
{
	drawingArea->offsetMoveRight();
	drawingArea->update();
}

void Window::moveLeftOnCanvas()
{
	drawingArea->offsetMoveLeft();
	drawingArea->update();
}

void Window::moveUpOnCanvas()
{
	drawingArea->offsetMoveUp();
	drawingArea->update();
}

void Window::moveDownOnCanvas()
{
	drawingArea->offsetMoveDown();
	drawingArea->update();
}

//Private

void Window::createMenuBar()
{
	menuBar = new QMenuBar();
	fileMenu = new QMenu("File");
	modeMenu = new QMenu("Mode");
	createModeMenu();
	menuBar->addMenu(fileMenu);
	menuBar->addMenu(modeMenu);
}

void Window::createModeMenu()
{
	/*
	openBuildModifyAct = new QAction(tr("&Build/Modify Menu"), this);
	openBuildModifyAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_B));
	connect(openBuildModifyAct, &QAction::triggered, this, &Window::openBuildModifyMenu);
	modeMenu->addAction(openBuildModifyAct);
	*/

	toWhiteBackgroundAct = new QAction(tr("&White Background"), this);
	connect(toWhiteBackgroundAct, &QAction::triggered, this, &Window::canvasToWhite);
	modeMenu->addAction(toWhiteBackgroundAct);

	toDarkBlueBackgroundAct = new QAction(tr("&Dark Blue Background"), this);
	connect(toDarkBlueBackgroundAct, &QAction::triggered, this, &Window::canvasToDarkBlue);
	modeMenu->addAction(toDarkBlueBackgroundAct);

	toBlackBackgroundAct = new QAction(tr("&Black Background"), this);
	connect(toBlackBackgroundAct, &QAction::triggered, this, &Window::canvasToBlack);
	modeMenu->addAction(toBlackBackgroundAct);
}

void Window::createOverallMenu()
{
	//Create the whole menu widget.
	top1Menu = new QWidget();
	//Add a layout.
	buildModifyMenu1 = new QHBoxLayout;
	QPalette pal2 = palette();
	pal2.setColor(QPalette::Window, Qt::red);
	top1Menu->setAutoFillBackground(true);
	top1Menu->setPalette(pal2);
	top1Menu->setLayout(buildModifyMenu1);

	//Create the different parts of it.
	createBuildModifyMenu();

	//Add all of the created menus back to the QStackedWidget.
	allMenus = new QStackedWidget;
	allMenus->addWidget(new QWidget());
	allMenus->addWidget(elementMenu);
	allMenus->addWidget(setConvertSpeedDistanceMenu);
	allMenus->setCurrentIndex(0);

}

void Window::createBuildModifyMenu()
{
	//Add the button to bring up the menu that allows the user to choose something to add to screen.
	elementMenuButton = new QToolButton();
	elementMenuButton->setMaximumSize(QSize(32,32));
	openElementMenuAct = new QAction;
	elementMenuButton->setDefaultAction(openElementMenuAct);
	connect(openElementMenuAct,&QAction::triggered,this,&Window::openElementMenu);
	elementMenuIcon = new QIcon(":/icons/icons/buildMenuIcon.png");
	elementMenuButton->setIcon(*elementMenuIcon);
	buildModifyMenu1->addWidget(elementMenuButton);

	//Add the button to bring up the menu that allows the user to set and convert speed and distances.
	setConvertSpeedDistanceMenuButton = new QToolButton();
	setConvertSpeedDistanceMenuButton->setMaximumSize(QSize(32,32));
	openSetConvertSpeedDistanceMenuAct = new QAction;
	setConvertSpeedDistanceMenuButton->setDefaultAction(openSetConvertSpeedDistanceMenuAct);
	connect(openSetConvertSpeedDistanceMenuAct,&QAction::triggered,this,&Window::openSetConvertSpeedDistanceMenu);
	setConvertSpeedDistanceMenuIcon = new QIcon(":/icons/icons/setDistanceSpeed.png");
	setConvertSpeedDistanceMenuButton->setIcon(*setConvertSpeedDistanceMenuIcon);
	buildModifyMenu1->addWidget(setConvertSpeedDistanceMenuButton);

	//Make part 2 of the menus.

	//Add the button that allows the user to change their signal aspect to add.
	setAspectButton = new QToolButton();
	setAspectButton->setMaximumSize(QSize(32,32));
	changeAspectAct = new QAction;
	setAspectButton->setDefaultAction(changeAspectAct);
	connect(changeAspectAct,&QAction::triggered,this,&Window::changeAspect);
	aspect4Icon = new QIcon(":/icons/icons/aspect4.png");
	aspect3Icon = new QIcon(":/icons/icons/aspect3.png");
	aspect2Icon = new QIcon(":/icons/icons/aspect2.png");
	aspectShuntIcon = new QIcon(":/icons/icons/aspectShunt.png");
	setAspectButton->setIcon(*aspect4Icon);
	buildModifyMenu1->addWidget(setAspectButton);
	//These menus will be on the QStackedWidget.
	//The user will be able to choose which one comes up.
	createElementMenu();
	createSetConvertSpeedDistanceMenu();
}

	//Element Menu

void Window::createElementMenu()
{
	elementMenu = new QWidget;
	QPalette pal = palette();
	pal.setColor(QPalette::Window, Qt::green);
	elementMenu->setAutoFillBackground(true);
	elementMenu->setPalette(pal);
	elementMenuLayout = new QGridLayout;
	elementMenuLayout->setContentsMargins(1, 1, 1, 1);
	elementMenuLayout->setHorizontalSpacing(1);
	elementMenuLayout->setVerticalSpacing(1);
	elementMenu->setLayout(elementMenuLayout);
	createElementBlock1();
	createElementBlock2();
	createElementBlock3();
	createElementBlock4();
	createElementBlock5();
	createElementBlock6();
}

void Window::createElementBlock1()
{
	straightHButton = new QToolButton();
	straightHButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseStraightHAct = new QAction();
	straightHButton->setDefaultAction(chooseStraightHAct);
	connect(chooseStraightHAct, &QAction::triggered, this, &Window::chooseStraightH);
	straightHIcon = new QIcon(":/graphics/graphics/straightH.png");
	straightHButton->setIcon(*straightHIcon);
	elementMenuLayout->addWidget(straightHButton, 0, 0);

	straightVButton = new QToolButton();
	straightVButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseStraightVAct = new QAction();
	straightVButton->setDefaultAction(chooseStraightVAct);
	connect(chooseStraightVAct, &QAction::triggered, this, &Window::chooseStraightV);
	straightVIcon = new QIcon(":/graphics/graphics/straightV.png");
	straightVButton->setIcon(*straightVIcon);
	elementMenuLayout->addWidget(straightVButton, 0, 1);

	directedLeftButton = new QToolButton();
	directedLeftButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseDirectedLeftAct = new QAction();
	directedLeftButton->setDefaultAction(chooseDirectedLeftAct);
	connect(chooseDirectedLeftAct, &QAction::triggered, this, &Window::chooseDirectedLeft);
	directedLeftIcon = new QIcon(":/graphics/graphics/directLeft.png");
	directedLeftButton->setIcon(*directedLeftIcon);
	elementMenuLayout->addWidget(directedLeftButton, 0, 2);

	directedRightButton = new QToolButton();
	directedRightButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseDirectedRightAct = new QAction();
	directedRightButton->setDefaultAction(chooseDirectedRightAct);
	connect(chooseDirectedRightAct, &QAction::triggered, this, &Window::chooseDirectedRight);
	directedRightIcon = new QIcon(":/graphics/graphics/directRight.png");
	directedRightButton->setIcon(*directedRightIcon);
	elementMenuLayout->addWidget(directedRightButton, 0, 3);

	directedUpButton = new QToolButton();
	directedUpButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseDirectedUpAct = new QAction();
	directedUpButton->setDefaultAction(chooseDirectedUpAct);
	connect(chooseDirectedUpAct, &QAction::triggered, this, &Window::chooseDirectedUp);
	directedUpIcon = new QIcon(":/graphics/graphics/directUp.png");
	directedUpButton->setIcon(*directedUpIcon);
	elementMenuLayout->addWidget(directedUpButton, 0, 4);

	directedDownButton = new QToolButton();
	directedDownButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseDirectedDownAct = new QAction();
	directedDownButton->setDefaultAction(chooseDirectedDownAct);
	connect(chooseDirectedDownAct, &QAction::triggered, this, &Window::chooseDirectedDown);
	directedDownIcon = new QIcon(":/graphics/graphics/directDown.png");
	directedDownButton->setIcon(*directedDownIcon);
	elementMenuLayout->addWidget(directedDownButton, 0, 5);

	straightRightUpButton = new QToolButton();
	straightRightUpButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseStraightRightUpAct = new QAction();
	straightRightUpButton->setDefaultAction(chooseStraightRightUpAct);
	connect(chooseStraightRightUpAct, &QAction::triggered, this, &Window::chooseStraightRightUp);
	straightRightUpIcon = new QIcon(":/graphics/graphics/straightRightUp.png");
	straightRightUpButton->setIcon(*straightRightUpIcon);
	elementMenuLayout->addWidget(straightRightUpButton, 0, 6);

	straightLeftUpButton = new QToolButton();
	straightLeftUpButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseStraightLeftUpAct = new QAction();
	straightLeftUpButton->setDefaultAction(chooseStraightLeftUpAct);
	connect(chooseStraightLeftUpAct, &QAction::triggered, this, &Window::chooseStraightLeftUp);
	straightLeftUpIcon = new QIcon(":/graphics/graphics/straightLeftUp.png");
	straightLeftUpButton->setIcon(*straightLeftUpIcon);
	elementMenuLayout->addWidget(straightLeftUpButton, 0, 7);

	directedRightUpButton = new QToolButton();
	directedRightUpButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseDirectedRightUpAct = new QAction();
	directedRightUpButton->setDefaultAction(chooseDirectedRightUpAct);
	connect(chooseDirectedRightUpAct, &QAction::triggered, this, &Window::chooseDirectedRightUp);
	directedRightUpIcon = new QIcon(":/graphics/graphics/directRightUp.png");
	directedRightUpButton->setIcon(*directedRightUpIcon);
	elementMenuLayout->addWidget(directedRightUpButton, 0, 8);

	directedLeftUpButton = new QToolButton();
	directedLeftUpButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseDirectedLeftUpAct = new QAction();
	directedLeftUpButton->setDefaultAction(chooseDirectedLeftUpAct);
	connect(chooseDirectedLeftUpAct, &QAction::triggered, this, &Window::chooseDirectedLeftUp);
	directedLeftUpIcon = new QIcon(":/graphics/graphics/directLeftUp.png");
	directedLeftUpButton->setIcon(*directedLeftUpIcon);
	elementMenuLayout->addWidget(directedLeftUpButton, 0, 9);

	directedLeftDownButton = new QToolButton();
	directedLeftDownButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseDirectedLeftDownAct = new QAction();
	directedLeftDownButton->setDefaultAction(chooseDirectedLeftDownAct);
	connect(chooseDirectedLeftDownAct, &QAction::triggered, this, &Window::chooseDirectedLeftDown);
	directedLeftDownIcon = new QIcon(":/graphics/graphics/directLeftDown.png");
	directedLeftDownButton->setIcon(*directedLeftDownIcon);
	elementMenuLayout->addWidget(directedLeftDownButton, 0, 10);

	directedRightDownButton = new QToolButton();
	directedRightDownButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseDirectedRightDownAct = new QAction();
	directedRightDownButton->setDefaultAction(chooseDirectedRightDownAct);
	connect(chooseDirectedRightDownAct, &QAction::triggered, this, &Window::chooseDirectedRightDown);
	directedRightDownIcon = new QIcon(":/graphics/graphics/directRightDown.png");
	directedRightDownButton->setIcon(*directedRightDownIcon);
	elementMenuLayout->addWidget(directedRightDownButton, 0, 11);

	tightCurve1Button = new QToolButton();
	tightCurve1Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseTightCurve1Act = new QAction();
	tightCurve1Button->setDefaultAction(chooseTightCurve1Act);
	connect(chooseTightCurve1Act, &QAction::triggered, this, &Window::chooseTightCurve1);
	tightCurve1Icon = new QIcon(":/graphics/graphics/tightCurve1.png");
	tightCurve1Button->setIcon(*tightCurve1Icon);
	elementMenuLayout->addWidget(tightCurve1Button, 0, 12);

	tightCurve2Button = new QToolButton();
	tightCurve2Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseTightCurve2Act = new QAction();
	tightCurve2Button->setDefaultAction(chooseTightCurve2Act);
	connect(chooseTightCurve2Act, &QAction::triggered, this, &Window::chooseTightCurve2);
	tightCurve2Icon = new QIcon(":/graphics/graphics/tightCurve2.png");
	tightCurve2Button->setIcon(*tightCurve2Icon);
	elementMenuLayout->addWidget(tightCurve2Button, 0, 13);

	tightCurve3Button = new QToolButton();
	tightCurve3Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseTightCurve3Act = new QAction();
	tightCurve3Button->setDefaultAction(chooseTightCurve3Act);
	connect(chooseTightCurve3Act, &QAction::triggered, this, &Window::chooseTightCurve3);
	tightCurve3Icon = new QIcon(":/graphics/graphics/tightCurve3.png");
	tightCurve3Button->setIcon(*tightCurve3Icon);
	elementMenuLayout->addWidget(tightCurve3Button, 0, 14);

	tightCurve4Button = new QToolButton();
	tightCurve4Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseTightCurve4Act = new QAction();
	tightCurve4Button->setDefaultAction(chooseTightCurve4Act);
	connect(chooseTightCurve4Act, &QAction::triggered, this, &Window::chooseTightCurve4);
	tightCurve4Icon = new QIcon(":/graphics/graphics/tightCurve4.png");
	tightCurve4Button->setIcon(*tightCurve4Icon);
	elementMenuLayout->addWidget(tightCurve4Button, 0, 15);

	curve1Button = new QToolButton();
	curve1Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseCurve1Act = new QAction();
	curve1Button->setDefaultAction(chooseCurve1Act);
	connect(chooseCurve1Act, &QAction::triggered, this, &Window::chooseCurve1);
	curve1Icon = new QIcon(":/graphics/graphics/curve1.png");
	curve1Button->setIcon(*curve1Icon);
	elementMenuLayout->addWidget(curve1Button, 0, 16);

	curve2Button = new QToolButton();
	curve2Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseCurve2Act = new QAction();
	curve2Button->setDefaultAction(chooseCurve2Act);
	connect(chooseCurve2Act, &QAction::triggered, this, &Window::chooseCurve2);
	curve2Icon = new QIcon(":/graphics/graphics/curve2.png");
	curve2Button->setIcon(*curve2Icon);
	elementMenuLayout->addWidget(curve2Button, 0, 17);

	curve3Button = new QToolButton();
	curve3Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseCurve3Act = new QAction();
	curve3Button->setDefaultAction(chooseCurve3Act);
	connect(chooseCurve3Act, &QAction::triggered, this, &Window::chooseCurve3);
	curve3Icon = new QIcon(":/graphics/graphics/curve3.png");
	curve3Button->setIcon(*curve3Icon);
	elementMenuLayout->addWidget(curve3Button, 0, 18);

	curve4Button = new QToolButton();
	curve4Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseCurve4Act = new QAction();
	curve4Button->setDefaultAction(chooseCurve4Act);
	connect(chooseCurve4Act, &QAction::triggered, this, &Window::chooseCurve4);
	curve4Icon = new QIcon(":/graphics/graphics/curve4.png");
	curve4Button->setIcon(*curve4Icon);
	elementMenuLayout->addWidget(curve4Button, 0, 19);

	linkLeftButton = new QToolButton();
	linkLeftButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseLinkLeftAct = new QAction();
	linkLeftButton->setDefaultAction(chooseLinkLeftAct);
	connect(chooseLinkLeftAct, &QAction::triggered, this, &Window::chooseLinkLeft);
	linkLeftIcon = new QIcon(":/graphics/graphics/linkLeftSet.png");
	linkLeftButton->setIcon(*linkLeftIcon);
	elementMenuLayout->addWidget(linkLeftButton, 1, 0);

	linkRightButton = new QToolButton();
	linkRightButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseLinkRightAct = new QAction();
	linkRightButton->setDefaultAction(chooseLinkRightAct);
	connect(chooseLinkRightAct, &QAction::triggered, this, &Window::chooseLinkRight);
	linkRightIcon = new QIcon(":/graphics/graphics/linkRightSet.png");
	linkRightButton->setIcon(*linkRightIcon);
	elementMenuLayout->addWidget(linkRightButton, 1, 1);

	linkDownButton = new QToolButton();
	linkDownButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseLinkDownAct = new QAction();
	linkDownButton->setDefaultAction(chooseLinkDownAct);
	connect(chooseLinkDownAct, &QAction::triggered, this, &Window::chooseLinkDown);
	linkDownIcon = new QIcon(":/graphics/graphics/linkDownSet.png");
	linkDownButton->setIcon(*linkDownIcon);
	elementMenuLayout->addWidget(linkDownButton, 1, 2);

	linkUpButton = new QToolButton();
	linkUpButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseLinkUpAct = new QAction();
	linkUpButton->setDefaultAction(chooseLinkUpAct);
	connect(chooseLinkUpAct, &QAction::triggered, this, &Window::chooseLinkUp);
	linkUpIcon = new QIcon(":/graphics/graphics/linkUpSet.png");
	linkUpButton->setIcon(*linkUpIcon);
	elementMenuLayout->addWidget(linkUpButton, 1, 3);

	linkLeftUpButton = new QToolButton();
	linkLeftUpButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseLinkLeftUpAct = new QAction();
	linkLeftUpButton->setDefaultAction(chooseLinkLeftUpAct);
	connect(chooseLinkLeftUpAct, &QAction::triggered, this, &Window::chooseLinkLeftUp);
	linkLeftUpIcon = new QIcon(":/graphics/graphics/linkLeftUpSet.png");
	linkLeftUpButton->setIcon(*linkLeftUpIcon);
	elementMenuLayout->addWidget(linkLeftUpButton, 1, 4);

	linkRightUpButton = new QToolButton();
	linkRightUpButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseLinkRightUpAct = new QAction();
	linkRightUpButton->setDefaultAction(chooseLinkRightUpAct);
	connect(chooseLinkRightUpAct, &QAction::triggered, this, &Window::chooseLinkRightUp);
	linkRightUpIcon = new QIcon(":/graphics/graphics/linkRightUpSet.png");
	linkRightUpButton->setIcon(*linkRightUpIcon);
	elementMenuLayout->addWidget(linkRightUpButton, 1, 5);

	linkLeftDownButton = new QToolButton();
	linkLeftDownButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseLinkLeftDownAct = new QAction();
	linkLeftDownButton->setDefaultAction(chooseLinkLeftDownAct);
	connect(chooseLinkLeftDownAct, &QAction::triggered, this, &Window::chooseLinkLeftDown);
	linkLeftDownIcon = new QIcon(":/graphics/graphics/linkLeftDownSet.png");
	linkLeftDownButton->setIcon(*linkLeftDownIcon);
	elementMenuLayout->addWidget(linkLeftDownButton, 1, 6);

	linkRightDownButton = new QToolButton();
	linkRightDownButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseLinkRightDownAct = new QAction();
	linkRightDownButton->setDefaultAction(chooseLinkRightDownAct);
	connect(chooseLinkRightDownAct, &QAction::triggered, this, &Window::chooseLinkRightDown);
	linkRightDownIcon = new QIcon(":/graphics/graphics/linkRightDownSet.png");
	linkRightDownButton->setIcon(*linkRightDownIcon);
	elementMenuLayout->addWidget(linkRightDownButton, 1, 7);

	exitLeftButton = new QToolButton();
	exitLeftButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseExitLeftAct = new QAction();
	exitLeftButton->setDefaultAction(chooseExitLeftAct);
	connect(chooseExitLeftAct, &QAction::triggered, this, &Window::chooseExitLeft);
	exitLeftIcon = new QIcon(":/graphics/graphics/exitLeft.png");
	exitLeftButton->setIcon(*exitLeftIcon);
	elementMenuLayout->addWidget(exitLeftButton, 1, 8);

	exitRightButton = new QToolButton();
	exitRightButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseExitRightAct = new QAction();
	exitRightButton->setDefaultAction(chooseExitRightAct);
	connect(chooseExitRightAct, &QAction::triggered, this, &Window::chooseExitRight);
	exitRightIcon = new QIcon(":/graphics/graphics/exitRight.png");
	exitRightButton->setIcon(*exitRightIcon);
	elementMenuLayout->addWidget(exitRightButton, 1, 9);

	exitDownButton = new QToolButton();
	exitDownButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseExitDownAct = new QAction();
	exitDownButton->setDefaultAction(chooseExitDownAct);
	connect(chooseExitDownAct, &QAction::triggered, this, &Window::chooseExitDown);
	exitDownIcon = new QIcon(":/graphics/graphics/exitDown.png");
	exitDownButton->setIcon(*exitDownIcon);
	elementMenuLayout->addWidget(exitDownButton, 1, 10);

	exitUpButton = new QToolButton();
	exitUpButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseExitUpAct = new QAction();
	exitUpButton->setDefaultAction(chooseExitUpAct);
	connect(chooseExitUpAct, &QAction::triggered, this, &Window::chooseExitUp);
	exitUpIcon = new QIcon(":/graphics/graphics/exitUp.png");
	exitUpButton->setIcon(*exitUpIcon);
	elementMenuLayout->addWidget(exitUpButton, 1, 11);

	exitLeftUpButton = new QToolButton();
	exitLeftUpButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseExitLeftUpAct = new QAction();
	exitLeftUpButton->setDefaultAction(chooseExitLeftUpAct);
	connect(chooseExitLeftUpAct, &QAction::triggered, this, &Window::chooseExitLeftUp);
	exitLeftUpIcon = new QIcon(":/graphics/graphics/exitLeftUp.png");
	exitLeftUpButton->setIcon(*exitLeftUpIcon);
	elementMenuLayout->addWidget(exitLeftUpButton, 1, 12);

	exitRightUpButton = new QToolButton();
	exitRightUpButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseExitRightUpAct = new QAction();
	exitRightUpButton->setDefaultAction(chooseExitRightUpAct);
	connect(chooseExitRightUpAct, &QAction::triggered, this, &Window::chooseExitRightUp);
	exitRightUpIcon = new QIcon(":/graphics/graphics/exitRightUp.png");
	exitRightUpButton->setIcon(*exitRightUpIcon);
	elementMenuLayout->addWidget(exitRightUpButton, 1, 13);

	exitLeftDownButton = new QToolButton();
	exitLeftDownButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseExitLeftDownAct = new QAction();
	exitLeftDownButton->setDefaultAction(chooseExitLeftDownAct);
	connect(chooseExitLeftDownAct, &QAction::triggered, this, &Window::chooseExitLeftDown);
	exitLeftDownIcon = new QIcon(":/graphics/graphics/exitLeftDown.png");
	exitLeftDownButton->setIcon(*exitLeftDownIcon);
	elementMenuLayout->addWidget(exitLeftDownButton, 1, 14);

	exitRightDownButton = new QToolButton();
	exitRightDownButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseExitRightDownAct = new QAction();
	exitRightDownButton->setDefaultAction(chooseExitRightDownAct);
	connect(chooseExitRightDownAct, &QAction::triggered, this, &Window::chooseExitRightDown);
	exitRightDownIcon = new QIcon(":/graphics/graphics/exitRightDown.png");
	exitRightDownButton->setIcon(*exitRightDownIcon);
	elementMenuLayout->addWidget(exitRightDownButton, 1, 15);

	curve5Button = new QToolButton();
	curve5Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseCurve5Act = new QAction();
	curve5Button->setDefaultAction(chooseCurve5Act);
	connect(chooseCurve5Act, &QAction::triggered, this, &Window::chooseCurve5);
	curve5Icon = new QIcon(":/graphics/graphics/curve5.png");
	curve5Button->setIcon(*curve5Icon);
	elementMenuLayout->addWidget(curve5Button, 1, 16);

	curve6Button = new QToolButton();
	curve6Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseCurve6Act = new QAction();
	curve6Button->setDefaultAction(chooseCurve6Act);
	connect(chooseCurve6Act, &QAction::triggered, this, &Window::chooseCurve6);
	curve6Icon = new QIcon(":/graphics/graphics/curve6.png");
	curve6Button->setIcon(*curve6Icon);
	elementMenuLayout->addWidget(curve6Button, 1, 17);

	curve7Button = new QToolButton();
	curve7Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseCurve7Act = new QAction();
	curve7Button->setDefaultAction(chooseCurve7Act);
	connect(chooseCurve7Act, &QAction::triggered, this, &Window::chooseCurve7);
	curve7Icon = new QIcon(":/graphics/graphics/curve7.png");
	curve7Button->setIcon(*curve7Icon);
	elementMenuLayout->addWidget(curve7Button, 1, 18);

	curve8Button = new QToolButton();
	curve8Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseCurve8Act = new QAction();
	curve8Button->setDefaultAction(chooseCurve8Act);
	connect(chooseCurve8Act, &QAction::triggered, this, &Window::chooseCurve8);
	curve8Icon = new QIcon(":/graphics/graphics/curve8.png");
	curve8Button->setIcon(*curve8Icon);
	elementMenuLayout->addWidget(curve8Button, 1, 19);

	bufferLeftButton = new QToolButton();
	bufferLeftButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseBufferLeftAct = new QAction();
	bufferLeftButton->setDefaultAction(chooseBufferLeftAct);
	connect(chooseBufferLeftAct, &QAction::triggered, this, &Window::chooseBufferLeft);
	bufferLeftIcon = new QIcon(":/graphics/graphics/bufferLeft.png");
	bufferLeftButton->setIcon(*bufferLeftIcon);
	elementMenuLayout->addWidget(bufferLeftButton, 2, 0);

	bufferRightButton = new QToolButton();
	bufferRightButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseBufferRightAct = new QAction();
	bufferRightButton->setDefaultAction(chooseBufferRightAct);
	connect(chooseBufferRightAct, &QAction::triggered, this, &Window::chooseBufferRight);
	bufferRightIcon = new QIcon(":/graphics/graphics/bufferRight.png");
	bufferRightButton->setIcon(*bufferRightIcon);
	elementMenuLayout->addWidget(bufferRightButton, 2, 1);

	bufferDownButton = new QToolButton();
	bufferDownButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseBufferDownAct = new QAction();
	bufferDownButton->setDefaultAction(chooseBufferDownAct);
	connect(chooseBufferDownAct, &QAction::triggered, this, &Window::chooseBufferDown);
	bufferDownIcon = new QIcon(":/graphics/graphics/bufferDown.png");
	bufferDownButton->setIcon(*bufferDownIcon);
	elementMenuLayout->addWidget(bufferDownButton, 2, 2);

	bufferUpButton = new QToolButton();
	bufferUpButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseBufferUpAct = new QAction();
	bufferUpButton->setDefaultAction(chooseBufferUpAct);
	connect(chooseBufferUpAct, &QAction::triggered, this, &Window::chooseBufferUp);
	bufferUpIcon = new QIcon(":/graphics/graphics/bufferUp.png");
	bufferUpButton->setIcon(*bufferUpIcon);
	elementMenuLayout->addWidget(bufferUpButton, 2, 3);

	bufferLeftUpButton = new QToolButton();
	bufferLeftUpButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseBufferLeftUpAct = new QAction();
	bufferLeftUpButton->setDefaultAction(chooseBufferLeftUpAct);
	connect(chooseBufferLeftUpAct, &QAction::triggered, this, &Window::chooseBufferLeftUp);
	bufferLeftUpIcon = new QIcon(":/graphics/graphics/bufferLeftUp.png");
	bufferLeftUpButton->setIcon(*bufferLeftUpIcon);
	elementMenuLayout->addWidget(bufferLeftUpButton, 2, 4);

	bufferRightUpButton = new QToolButton();
	bufferRightUpButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseBufferRightUpAct = new QAction();
	bufferRightUpButton->setDefaultAction(chooseBufferRightUpAct);
	connect(chooseBufferRightUpAct, &QAction::triggered, this, &Window::chooseBufferRightUp);
	bufferRightUpIcon = new QIcon(":/graphics/graphics/bufferRightUp.png");
	bufferRightUpButton->setIcon(*bufferRightUpIcon);
	elementMenuLayout->addWidget(bufferRightUpButton, 2, 5);

	bufferLeftDownButton = new QToolButton();
	bufferLeftDownButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseBufferLeftDownAct = new QAction();
	bufferLeftDownButton->setDefaultAction(chooseBufferLeftDownAct);
	connect(chooseBufferLeftDownAct, &QAction::triggered, this, &Window::chooseBufferLeftDown);
	bufferLeftDownIcon = new QIcon(":/graphics/graphics/bufferLeftDown.png");
	bufferLeftDownButton->setIcon(*bufferLeftDownIcon);
	elementMenuLayout->addWidget(bufferLeftDownButton, 2, 6);

	bufferRightDownButton = new QToolButton();
	bufferRightDownButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseBufferRightDownAct = new QAction();
	bufferRightDownButton->setDefaultAction(chooseBufferRightDownAct);
	connect(chooseBufferRightDownAct, &QAction::triggered, this, &Window::chooseBufferRightDown);
	bufferRightDownIcon = new QIcon(":/graphics/graphics/bufferRightDown.png");
	bufferRightDownButton->setIcon(*bufferRightDownIcon);
	elementMenuLayout->addWidget(bufferRightDownButton, 2, 7);

	signalLeftButton = new QToolButton();
	signalLeftButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSignalLeftAct = new QAction();
	signalLeftButton->setDefaultAction(chooseSignalLeftAct);
	connect(chooseSignalLeftAct, &QAction::triggered, this, &Window::chooseSignalLeft);
	signalLeftIcon = new QIcon(":/graphics/graphics/signalLeft.png");
	shuntLeftIcon = new QIcon(":/graphics/graphics/shuntLeftRed.png");
	signalLeftButton->setIcon(*signalLeftIcon);
	elementMenuLayout->addWidget(signalLeftButton, 2, 8);

	signalRightButton = new QToolButton();
	signalRightButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSignalRightAct = new QAction();
	signalRightButton->setDefaultAction(chooseSignalRightAct);
	connect(chooseSignalRightAct, &QAction::triggered, this, &Window::chooseSignalRight);
	signalRightIcon = new QIcon(":/graphics/graphics/signalRight.png");
	shuntRightIcon = new QIcon(":/graphics/graphics/shuntRightRed.png");
	signalRightButton->setIcon(*signalRightIcon);
	elementMenuLayout->addWidget(signalRightButton, 2, 9);

	signalDownButton = new QToolButton();
	signalDownButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSignalDownAct = new QAction();
	signalDownButton->setDefaultAction(chooseSignalDownAct);
	connect(chooseSignalDownAct, &QAction::triggered, this, &Window::chooseSignalDown);
	signalDownIcon = new QIcon(":/graphics/graphics/signalDown.png");
	shuntDownIcon = new QIcon(":/graphics/graphics/shuntDownRed.png");
	signalDownButton->setIcon(*signalDownIcon);
	elementMenuLayout->addWidget(signalDownButton, 2, 10);

	signalUpButton = new QToolButton();
	signalUpButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSignalUpAct = new QAction();
	signalUpButton->setDefaultAction(chooseSignalUpAct);
	connect(chooseSignalUpAct, &QAction::triggered, this, &Window::chooseSignalUp);
	signalUpIcon = new QIcon(":/graphics/graphics/signalUp.png");
	shuntUpIcon = new QIcon(":/graphics/graphics/shuntUpRed.png");
	signalUpButton->setIcon(*signalUpIcon);
	elementMenuLayout->addWidget(signalUpButton, 2, 11);

	signalLeftUpButton = new QToolButton();
	signalLeftUpButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSignalLeftUpAct = new QAction();
	signalLeftUpButton->setDefaultAction(chooseSignalLeftUpAct);
	connect(chooseSignalLeftUpAct, &QAction::triggered, this, &Window::chooseSignalLeftUp);
	signalLeftUpIcon = new QIcon(":/graphics/graphics/signalLeftUp.png");
	shuntLeftUpIcon = new QIcon(":/graphics/graphics/shuntLeftUpRed.png");
	signalLeftUpButton->setIcon(*signalLeftUpIcon);
	elementMenuLayout->addWidget(signalLeftUpButton, 2, 12);

	signalRightUpButton = new QToolButton();
	signalRightUpButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSignalRightUpAct = new QAction();
	signalRightUpButton->setDefaultAction(chooseSignalRightUpAct);
	connect(chooseSignalRightUpAct, &QAction::triggered, this, &Window::chooseSignalRightUp);
	signalRightUpIcon = new QIcon(":/graphics/graphics/signalRightUp.png");
	shuntRightUpIcon = new QIcon(":/graphics/graphics/shuntRightUpRed.png");
	signalRightUpButton->setIcon(*signalRightUpIcon);
	elementMenuLayout->addWidget(signalRightUpButton, 2, 13);

	signalLeftDownButton = new QToolButton();
	signalLeftDownButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSignalLeftDownAct = new QAction();
	signalLeftDownButton->setDefaultAction(chooseSignalLeftDownAct);
	connect(chooseSignalLeftDownAct, &QAction::triggered, this, &Window::chooseSignalLeftDown);
	signalLeftDownIcon = new QIcon(":/graphics/graphics/signalLeftDown.png");
	shuntLeftDownIcon = new QIcon(":/graphics/graphics/shuntLeftDownRed.png");
	signalLeftDownButton->setIcon(*signalLeftDownIcon);
	elementMenuLayout->addWidget(signalLeftDownButton, 2, 14);

	signalRightDownButton = new QToolButton();
	signalRightDownButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSignalRightDownAct = new QAction();
	signalRightDownButton->setDefaultAction(chooseSignalRightDownAct);
	connect(chooseSignalRightDownAct, &QAction::triggered, this, &Window::chooseSignalRightDown);
	signalRightDownIcon = new QIcon(":/graphics/graphics/signalRightDown.png");
	shuntRightDownIcon = new QIcon(":/graphics/graphics/shuntRightDownRed.png");
	signalRightDownButton->setIcon(*signalRightDownIcon);
	elementMenuLayout->addWidget(signalRightDownButton, 2, 15);

	bridge1Button = new QToolButton();
	bridge1Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseBridge1Act = new QAction();
	bridge1Button->setDefaultAction(chooseBridge1Act);
	connect(chooseBridge1Act, &QAction::triggered, this, &Window::chooseBridge1);
	bridge1Icon = new QIcon(":/graphics/graphics/bridgeSet1.png");
	bridge1Button->setIcon(*bridge1Icon);
	elementMenuLayout->addWidget(bridge1Button, 2, 16);

	bridge2Button = new QToolButton();
	bridge2Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseBridge2Act = new QAction();
	bridge2Button->setDefaultAction(chooseBridge2Act);
	connect(chooseBridge2Act, &QAction::triggered, this, &Window::chooseBridge2);
	bridge2Icon = new QIcon(":/graphics/graphics/bridgeSet2.png");
	bridge2Button->setIcon(*bridge2Icon);
	elementMenuLayout->addWidget(bridge2Button, 2, 17);

	underpass1Button = new QToolButton();
	underpass1Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseUnderpass1Act = new QAction();
	underpass1Button->setDefaultAction(chooseUnderpass1Act);
	connect(chooseUnderpass1Act, &QAction::triggered, this, &Window::chooseUnderpass1);
	underpass1Icon = new QIcon(":/graphics/graphics/underpassSet1.png");
	underpass1Button->setIcon(*underpass1Icon);
	elementMenuLayout->addWidget(underpass1Button, 2, 18);

	underpass2Button = new QToolButton();
	underpass2Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseUnderpass2Act = new QAction();
	underpass2Button->setDefaultAction(chooseUnderpass2Act);
	connect(chooseUnderpass2Act, &QAction::triggered, this, &Window::chooseUnderpass2);
	underpass2Icon = new QIcon(":/graphics/graphics/underpassSet2.png");
	underpass2Button->setIcon(*underpass2Icon);
	elementMenuLayout->addWidget(underpass2Button, 2, 19);

}

void Window::createElementBlock2()
{
	elementMenuLayout->addItem(new QSpacerItem(elementMenuButtonSize,elementMenuButtonSize),0,20);
	elementMenuLayout->addItem(new QSpacerItem(elementMenuButtonSize,elementMenuButtonSize),1,20);
	elementMenuLayout->addItem(new QSpacerItem(elementMenuButtonSize,elementMenuButtonSize),2,20);

	switchTight1Button = new QToolButton();
	switchTight1Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitchTight1Act = new QAction();
	switchTight1Button->setDefaultAction(chooseSwitchTight1Act);
	connect(chooseSwitchTight1Act, &QAction::triggered, this, &Window::chooseSwitchTight1);
	switchTight1Icon = new QIcon(":/graphics/graphics/switchTight1.png");
	switchTight1Button->setIcon(*switchTight1Icon);
	elementMenuLayout->addWidget(switchTight1Button, 0, 21);

	switchTight2Button = new QToolButton();
	switchTight2Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitchTight2Act = new QAction();
	switchTight2Button->setDefaultAction(chooseSwitchTight2Act);
	connect(chooseSwitchTight2Act, &QAction::triggered, this, &Window::chooseSwitchTight2);
	switchTight2Icon = new QIcon(":/graphics/graphics/switchTight2.png");
	switchTight2Button->setIcon(*switchTight2Icon);
	elementMenuLayout->addWidget(switchTight2Button, 0, 22);

	switchTight3Button = new QToolButton();
	switchTight3Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitchTight3Act = new QAction();
	switchTight3Button->setDefaultAction(chooseSwitchTight3Act);
	connect(chooseSwitchTight3Act, &QAction::triggered, this, &Window::chooseSwitchTight3);
	switchTight3Icon = new QIcon(":/graphics/graphics/switchTight3.png");
	switchTight3Button->setIcon(*switchTight3Icon);
	elementMenuLayout->addWidget(switchTight3Button, 0, 23);

	switchTight4Button = new QToolButton();
	switchTight4Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitchTight4Act = new QAction();
	switchTight4Button->setDefaultAction(chooseSwitchTight4Act);
	connect(chooseSwitchTight4Act, &QAction::triggered, this, &Window::chooseSwitchTight4);
	switchTight4Icon = new QIcon(":/graphics/graphics/switchTight4.png");
	switchTight4Button->setIcon(*switchTight4Icon);
	elementMenuLayout->addWidget(switchTight4Button, 0, 24);

	switchTight5Button = new QToolButton();
	switchTight5Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitchTight5Act = new QAction();
	switchTight5Button->setDefaultAction(chooseSwitchTight5Act);
	connect(chooseSwitchTight5Act, &QAction::triggered, this, &Window::chooseSwitchTight5);
	switchTight5Icon = new QIcon(":/graphics/graphics/switchTight5.png");
	switchTight5Button->setIcon(*switchTight5Icon);
	elementMenuLayout->addWidget(switchTight5Button, 0, 25);

	switchTight6Button = new QToolButton();
	switchTight6Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitchTight6Act = new QAction();
	switchTight6Button->setDefaultAction(chooseSwitchTight6Act);
	connect(chooseSwitchTight6Act, &QAction::triggered, this, &Window::chooseSwitchTight6);
	switchTight6Icon = new QIcon(":/graphics/graphics/switchTight6.png");
	switchTight6Button->setIcon(*switchTight6Icon);
	elementMenuLayout->addWidget(switchTight6Button, 0, 26);

	switchTight7Button = new QToolButton();
	switchTight7Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitchTight7Act = new QAction();
	switchTight7Button->setDefaultAction(chooseSwitchTight7Act);
	connect(chooseSwitchTight7Act, &QAction::triggered, this, &Window::chooseSwitchTight7);
	switchTight7Icon = new QIcon(":/graphics/graphics/switchTight7.png");
	switchTight7Button->setIcon(*switchTight7Icon);
	elementMenuLayout->addWidget(switchTight7Button, 0, 27);

	switchTight8Button = new QToolButton();
	switchTight8Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitchTight8Act = new QAction();
	switchTight8Button->setDefaultAction(chooseSwitchTight8Act);
	connect(chooseSwitchTight8Act, &QAction::triggered, this, &Window::chooseSwitchTight8);
	switchTight8Icon = new QIcon(":/graphics/graphics/switchTight8.png");
	switchTight8Button->setIcon(*switchTight8Icon);
	elementMenuLayout->addWidget(switchTight8Button, 0, 28);

	switchSplit1Button = new QToolButton();
	switchSplit1Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitchSplit1Act = new QAction();
	switchSplit1Button->setDefaultAction(chooseSwitchSplit1Act);
	connect(chooseSwitchSplit1Act, &QAction::triggered, this, &Window::chooseSwitchSplit1);
	switchSplit1Icon = new QIcon(":/graphics/graphics/switchSplit1.png");
	switchSplit1Button->setIcon(*switchSplit1Icon);
	elementMenuLayout->addWidget(switchSplit1Button, 0, 29);

	switchSplit2Button = new QToolButton();
	switchSplit2Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitchSplit2Act = new QAction();
	switchSplit2Button->setDefaultAction(chooseSwitchSplit2Act);
	connect(chooseSwitchSplit2Act, &QAction::triggered, this, &Window::chooseSwitchSplit2);
	switchSplit2Icon = new QIcon(":/graphics/graphics/switchSplit2.png");
	switchSplit2Button->setIcon(*switchSplit2Icon);
	elementMenuLayout->addWidget(switchSplit2Button, 0, 30);

	switchSplit3Button = new QToolButton();
	switchSplit3Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitchSplit3Act = new QAction();
	switchSplit3Button->setDefaultAction(chooseSwitchSplit3Act);
	connect(chooseSwitchSplit3Act, &QAction::triggered, this, &Window::chooseSwitchSplit3);
	switchSplit3Icon = new QIcon(":/graphics/graphics/switchSplit3.png");
	switchSplit3Button->setIcon(*switchSplit3Icon);
	elementMenuLayout->addWidget(switchSplit3Button, 0, 31);

	switch1Button = new QToolButton();
	switch1Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitch1Act = new QAction();
	switch1Button->setDefaultAction(chooseSwitch1Act);
	connect(chooseSwitch1Act, &QAction::triggered, this, &Window::chooseSwitch1);
	switch1Icon = new QIcon(":/graphics/graphics/switch1.png");
	switch1Button->setIcon(*switch1Icon);
	elementMenuLayout->addWidget(switch1Button, 1, 21);

	switch2Button = new QToolButton();
	switch2Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitch2Act = new QAction();
	switch2Button->setDefaultAction(chooseSwitch2Act);
	connect(chooseSwitch2Act, &QAction::triggered, this, &Window::chooseSwitch2);
	switch2Icon = new QIcon(":/graphics/graphics/switch2.png");
	switch2Button->setIcon(*switch2Icon);
	elementMenuLayout->addWidget(switch2Button, 1, 22);

	switch3Button = new QToolButton();
	switch3Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitch3Act = new QAction();
	switch3Button->setDefaultAction(chooseSwitch3Act);
	connect(chooseSwitch3Act, &QAction::triggered, this, &Window::chooseSwitch3);
	switch3Icon = new QIcon(":/graphics/graphics/switch3.png");
	switch3Button->setIcon(*switch3Icon);
	elementMenuLayout->addWidget(switch3Button, 1, 23);

	switch4Button = new QToolButton();
	switch4Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitch4Act = new QAction();
	switch4Button->setDefaultAction(chooseSwitch4Act);
	connect(chooseSwitch4Act, &QAction::triggered, this, &Window::chooseSwitch4);
	switch4Icon = new QIcon(":/graphics/graphics/switch4.png");
	switch4Button->setIcon(*switch4Icon);
	elementMenuLayout->addWidget(switch4Button, 1, 24);

	switch5Button = new QToolButton();
	switch5Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitch5Act = new QAction();
	switch5Button->setDefaultAction(chooseSwitch5Act);
	connect(chooseSwitch5Act, &QAction::triggered, this, &Window::chooseSwitch5);
	switch5Icon = new QIcon(":/graphics/graphics/switch5.png");
	switch5Button->setIcon(*switch5Icon);
	elementMenuLayout->addWidget(switch5Button, 1, 25);

	switch6Button = new QToolButton();
	switch6Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitch6Act = new QAction();
	switch6Button->setDefaultAction(chooseSwitch6Act);
	connect(chooseSwitch6Act, &QAction::triggered, this, &Window::chooseSwitch6);
	switch6Icon = new QIcon(":/graphics/graphics/switch6.png");
	switch6Button->setIcon(*switch6Icon);
	elementMenuLayout->addWidget(switch6Button, 1, 26);

	switch7Button = new QToolButton();
	switch7Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitch7Act = new QAction();
	switch7Button->setDefaultAction(chooseSwitch7Act);
	connect(chooseSwitch7Act, &QAction::triggered, this, &Window::chooseSwitch7);
	switch7Icon = new QIcon(":/graphics/graphics/switch7.png");
	switch7Button->setIcon(*switch7Icon);
	elementMenuLayout->addWidget(switch7Button, 1, 27);

	switch8Button = new QToolButton();
	switch8Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitch8Act = new QAction();
	switch8Button->setDefaultAction(chooseSwitch8Act);
	connect(chooseSwitch8Act, &QAction::triggered, this, &Window::chooseSwitch8);
	switch8Icon = new QIcon(":/graphics/graphics/switch8.png");
	switch8Button->setIcon(*switch8Icon);
	elementMenuLayout->addWidget(switch8Button, 1, 28);

	switchSplit4Button = new QToolButton();
	switchSplit4Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitchSplit4Act = new QAction();
	switchSplit4Button->setDefaultAction(chooseSwitchSplit4Act);
	connect(chooseSwitchSplit4Act, &QAction::triggered, this, &Window::chooseSwitchSplit4);
	switchSplit4Icon = new QIcon(":/graphics/graphics/switchSplit4.png");
	switchSplit4Button->setIcon(*switchSplit4Icon);
	elementMenuLayout->addWidget(switchSplit4Button, 1, 29);

	switchSplit5Button = new QToolButton();
	switchSplit5Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitchSplit5Act = new QAction();
	switchSplit5Button->setDefaultAction(chooseSwitchSplit5Act);
	connect(chooseSwitchSplit5Act, &QAction::triggered, this, &Window::chooseSwitchSplit5);
	switchSplit5Icon = new QIcon(":/graphics/graphics/switchSplit5.png");
	switchSplit5Button->setIcon(*switchSplit5Icon);
	elementMenuLayout->addWidget(switchSplit5Button, 1, 30);

	switchSplit6Button = new QToolButton();
	switchSplit6Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitchSplit6Act = new QAction();
	switchSplit6Button->setDefaultAction(chooseSwitchSplit6Act);
	connect(chooseSwitchSplit6Act, &QAction::triggered, this, &Window::chooseSwitchSplit6);
	switchSplit6Icon = new QIcon(":/graphics/graphics/switchSplit6.png");
	switchSplit6Button->setIcon(*switchSplit6Icon);
	elementMenuLayout->addWidget(switchSplit6Button, 1, 31);

	switch9Button = new QToolButton();
	switch9Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitch9Act = new QAction();
	switch9Button->setDefaultAction(chooseSwitch9Act);
	connect(chooseSwitch9Act, &QAction::triggered, this, &Window::chooseSwitch9);
	switch9Icon = new QIcon(":/graphics/graphics/switch9.png");
	switch9Button->setIcon(*switch9Icon);
	elementMenuLayout->addWidget(switch9Button, 2, 21);

	switch10Button = new QToolButton();
	switch10Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitch10Act = new QAction();
	switch10Button->setDefaultAction(chooseSwitch10Act);
	connect(chooseSwitch10Act, &QAction::triggered, this, &Window::chooseSwitch10);
	switch10Icon = new QIcon(":/graphics/graphics/switch10.png");
	switch10Button->setIcon(*switch10Icon);
	elementMenuLayout->addWidget(switch10Button, 2, 22);

	switch11Button = new QToolButton();
	switch11Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitch11Act = new QAction();
	switch11Button->setDefaultAction(chooseSwitch11Act);
	connect(chooseSwitch11Act, &QAction::triggered, this, &Window::chooseSwitch11);
	switch11Icon = new QIcon(":/graphics/graphics/switch11.png");
	switch11Button->setIcon(*switch11Icon);
	elementMenuLayout->addWidget(switch11Button, 2, 23);

	switch12Button = new QToolButton();
	switch12Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitch12Act = new QAction();
	switch12Button->setDefaultAction(chooseSwitch12Act);
	connect(chooseSwitch12Act, &QAction::triggered, this, &Window::chooseSwitch12);
	switch12Icon = new QIcon(":/graphics/graphics/switch12.png");
	switch12Button->setIcon(*switch12Icon);
	elementMenuLayout->addWidget(switch12Button, 2, 24);

	switch13Button = new QToolButton();
	switch13Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitch13Act = new QAction();
	switch13Button->setDefaultAction(chooseSwitch13Act);
	connect(chooseSwitch13Act, &QAction::triggered, this, &Window::chooseSwitch13);
	switch13Icon = new QIcon(":/graphics/graphics/switch13.png");
	switch13Button->setIcon(*switch13Icon);
	elementMenuLayout->addWidget(switch13Button, 2, 25);

	switch14Button = new QToolButton();
	switch14Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitch14Act = new QAction();
	switch14Button->setDefaultAction(chooseSwitch14Act);
	connect(chooseSwitch14Act, &QAction::triggered, this, &Window::chooseSwitch14);
	switch14Icon = new QIcon(":/graphics/graphics/switch14.png");
	switch14Button->setIcon(*switch14Icon);
	elementMenuLayout->addWidget(switch14Button, 2, 26);

	switch15Button = new QToolButton();
	switch15Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitch15Act = new QAction();
	switch15Button->setDefaultAction(chooseSwitch15Act);
	connect(chooseSwitch15Act, &QAction::triggered, this, &Window::chooseSwitch15);
	switch15Icon = new QIcon(":/graphics/graphics/switch15.png");
	switch15Button->setIcon(*switch15Icon);
	elementMenuLayout->addWidget(switch15Button, 2, 27);

	switch16Button = new QToolButton();
	switch16Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitch16Act = new QAction();
	switch16Button->setDefaultAction(chooseSwitch16Act);
	connect(chooseSwitch16Act, &QAction::triggered, this, &Window::chooseSwitch16);
	switch16Icon = new QIcon(":/graphics/graphics/switch16.png");
	switch16Button->setIcon(*switch16Icon);
	elementMenuLayout->addWidget(switch16Button, 2, 28);

	switchSplit7Button = new QToolButton();
	switchSplit7Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitchSplit7Act = new QAction();
	switchSplit7Button->setDefaultAction(chooseSwitchSplit7Act);
	connect(chooseSwitchSplit7Act, &QAction::triggered, this, &Window::chooseSwitchSplit7);
	switchSplit7Icon = new QIcon(":/graphics/graphics/switchSplit7.png");
	switchSplit7Button->setIcon(*switchSplit7Icon);
	elementMenuLayout->addWidget(switchSplit7Button, 2, 29);

	switchSplit8Button = new QToolButton();
	switchSplit8Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseSwitchSplit8Act = new QAction();
	switchSplit8Button->setDefaultAction(chooseSwitchSplit8Act);
	connect(chooseSwitchSplit8Act, &QAction::triggered, this, &Window::chooseSwitchSplit8);
	switchSplit8Icon = new QIcon(":/graphics/graphics/switchSplit8.png");
	switchSplit8Button->setIcon(*switchSplit8Icon);
	elementMenuLayout->addWidget(switchSplit8Button, 2, 30);
}

void Window::createElementBlock3()
{
	elementMenuLayout->addItem(new QSpacerItem(elementMenuButtonSize,elementMenuButtonSize),0,32);
	elementMenuLayout->addItem(new QSpacerItem(elementMenuButtonSize,elementMenuButtonSize),1,32);
	elementMenuLayout->addItem(new QSpacerItem(elementMenuButtonSize,elementMenuButtonSize),2,32);

	crossover1Button = new QToolButton();
	crossover1Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseCrossover1Act = new QAction();
	crossover1Button->setDefaultAction(chooseCrossover1Act);
	connect(chooseCrossover1Act, &QAction::triggered, this, &Window::chooseCrossover1);
	crossover1Icon = new QIcon(":/graphics/graphics/crossover1.png");
	crossover1Button->setIcon(*crossover1Icon);
	elementMenuLayout->addWidget(crossover1Button, 0, 33);

	crossover2Button = new QToolButton();
	crossover2Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseCrossover2Act = new QAction();
	crossover2Button->setDefaultAction(chooseCrossover2Act);
	connect(chooseCrossover2Act, &QAction::triggered, this, &Window::chooseCrossover2);
	crossover2Icon = new QIcon(":/graphics/graphics/crossover2.png");
	crossover2Button->setIcon(*crossover2Icon);
	elementMenuLayout->addWidget(crossover2Button, 0, 34);

	flyover1Button = new QToolButton();
	flyover1Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseFlyover1Act = new QAction();
	flyover1Button->setDefaultAction(chooseFlyover1Act);
	connect(chooseFlyover1Act, &QAction::triggered, this, &Window::chooseFlyover1);
	flyover1Icon = new QIcon(":/graphics/graphics/flyover1.png");
	flyover1Button->setIcon(*flyover1Icon);
	elementMenuLayout->addWidget(flyover1Button, 0, 35);

	flyover2Button = new QToolButton();
	flyover2Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseFlyover2Act = new QAction();
	flyover2Button->setDefaultAction(chooseFlyover2Act);
	connect(chooseFlyover2Act, &QAction::triggered, this, &Window::chooseFlyover2);
	flyover2Icon = new QIcon(":/graphics/graphics/flyover2.png");
	flyover2Button->setIcon(*flyover2Icon);
	elementMenuLayout->addWidget(flyover2Button, 0, 36);

	flyover3Button = new QToolButton();
	flyover3Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseFlyover3Act = new QAction();
	flyover3Button->setDefaultAction(chooseFlyover3Act);
	connect(chooseFlyover3Act, &QAction::triggered, this, &Window::chooseFlyover3);
	flyover3Icon = new QIcon(":/graphics/graphics/flyover3.png");
	flyover3Button->setIcon(*flyover3Icon);
	elementMenuLayout->addWidget(flyover3Button, 0, 37);

	flyover4Button = new QToolButton();
	flyover4Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseFlyover4Act = new QAction();
	flyover4Button->setDefaultAction(chooseFlyover4Act);
	connect(chooseFlyover4Act, &QAction::triggered, this, &Window::chooseFlyover4);
	flyover4Icon = new QIcon(":/graphics/graphics/flyover4.png");
	flyover4Button->setIcon(*flyover4Icon);
	elementMenuLayout->addWidget(flyover4Button, 0, 38);

	crossover3Button = new QToolButton();
	crossover3Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseCrossover3Act = new QAction();
	crossover3Button->setDefaultAction(chooseCrossover3Act);
	connect(chooseCrossover3Act, &QAction::triggered, this, &Window::chooseCrossover3);
	crossover3Icon = new QIcon(":/graphics/graphics/crossover3.png");
	crossover3Button->setIcon(*crossover3Icon);
	elementMenuLayout->addWidget(crossover3Button, 1, 33);

	crossover4Button = new QToolButton();
	crossover4Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseCrossover4Act = new QAction();
	crossover4Button->setDefaultAction(chooseCrossover4Act);
	connect(chooseCrossover4Act, &QAction::triggered, this, &Window::chooseCrossover4);
	crossover4Icon = new QIcon(":/graphics/graphics/crossover4.png");
	crossover4Button->setIcon(*crossover4Icon);
	elementMenuLayout->addWidget(crossover4Button, 1, 34);

	flyover5Button = new QToolButton();
	flyover5Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseFlyover5Act = new QAction();
	flyover5Button->setDefaultAction(chooseFlyover5Act);
	connect(chooseFlyover5Act, &QAction::triggered, this, &Window::chooseFlyover5);
	flyover5Icon = new QIcon(":/graphics/graphics/flyover5.png");
	flyover5Button->setIcon(*flyover5Icon);
	elementMenuLayout->addWidget(flyover5Button, 1, 35);

	flyover6Button = new QToolButton();
	flyover6Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseFlyover6Act = new QAction();
	flyover6Button->setDefaultAction(chooseFlyover6Act);
	connect(chooseFlyover6Act, &QAction::triggered, this, &Window::chooseFlyover6);
	flyover6Icon = new QIcon(":/graphics/graphics/flyover6.png");
	flyover6Button->setIcon(*flyover6Icon);
	elementMenuLayout->addWidget(flyover6Button, 1, 36);

	flyover7Button = new QToolButton();
	flyover7Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseFlyover7Act = new QAction();
	flyover7Button->setDefaultAction(chooseFlyover7Act);
	connect(chooseFlyover7Act, &QAction::triggered, this, &Window::chooseFlyover7);
	flyover7Icon = new QIcon(":/graphics/graphics/flyover7.png");
	flyover7Button->setIcon(*flyover7Icon);
	elementMenuLayout->addWidget(flyover7Button, 1, 37);

	flyover8Button = new QToolButton();
	flyover8Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseFlyover8Act = new QAction();
	flyover8Button->setDefaultAction(chooseFlyover8Act);
	connect(chooseFlyover8Act, &QAction::triggered, this, &Window::chooseFlyover8);
	flyover8Icon = new QIcon(":/graphics/graphics/flyover8.png");
	flyover8Button->setIcon(*flyover8Icon);
	elementMenuLayout->addWidget(flyover8Button, 1, 38);

	crossover5Button = new QToolButton();
	crossover5Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseCrossover5Act = new QAction();
	crossover5Button->setDefaultAction(chooseCrossover5Act);
	connect(chooseCrossover5Act, &QAction::triggered, this, &Window::chooseCrossover5);
	crossover5Icon = new QIcon(":/graphics/graphics/crossover5.png");
	crossover5Button->setIcon(*crossover5Icon);
	elementMenuLayout->addWidget(crossover5Button, 2, 33);

	crossover6Button = new QToolButton();
	crossover6Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseCrossover6Act = new QAction();
	crossover6Button->setDefaultAction(chooseCrossover6Act);
	connect(chooseCrossover6Act, &QAction::triggered, this, &Window::chooseCrossover6);
	crossover6Icon = new QIcon(":/graphics/graphics/crossover6.png");
	crossover6Button->setIcon(*crossover6Icon);
	elementMenuLayout->addWidget(crossover6Button, 2, 34);

	flyover9Button = new QToolButton();
	flyover9Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseFlyover9Act = new QAction();
	flyover9Button->setDefaultAction(chooseFlyover9Act);
	connect(chooseFlyover9Act, &QAction::triggered, this, &Window::chooseFlyover9);
	flyover9Icon = new QIcon(":/graphics/graphics/flyover9.png");
	flyover9Button->setIcon(*flyover9Icon);
	elementMenuLayout->addWidget(flyover9Button, 2, 35);

	flyover10Button = new QToolButton();
	flyover10Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseFlyover10Act = new QAction();
	flyover10Button->setDefaultAction(chooseFlyover10Act);
	connect(chooseFlyover10Act, &QAction::triggered, this, &Window::chooseFlyover10);
	flyover10Icon = new QIcon(":/graphics/graphics/flyover10.png");
	flyover10Button->setIcon(*flyover10Icon);
	elementMenuLayout->addWidget(flyover10Button, 2, 36);

	flyover11Button = new QToolButton();
	flyover11Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseFlyover11Act = new QAction();
	flyover11Button->setDefaultAction(chooseFlyover11Act);
	connect(chooseFlyover11Act, &QAction::triggered, this, &Window::chooseFlyover11);
	flyover11Icon = new QIcon(":/graphics/graphics/flyover11.png");
	flyover11Button->setIcon(*flyover11Icon);
	elementMenuLayout->addWidget(flyover11Button, 2, 37);

	flyover12Button = new QToolButton();
	flyover12Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseFlyover12Act = new QAction();
	flyover12Button->setDefaultAction(chooseFlyover12Act);
	connect(chooseFlyover12Act, &QAction::triggered, this, &Window::chooseFlyover12);
	flyover12Icon = new QIcon(":/graphics/graphics/flyover12.png");
	flyover12Button->setIcon(*flyover12Icon);
	elementMenuLayout->addWidget(flyover12Button, 2, 38);

}

void Window::createElementBlock4()
{
	elementMenuLayout->addItem(new QSpacerItem(elementMenuButtonSize,elementMenuButtonSize),0,39);
	elementMenuLayout->addItem(new QSpacerItem(elementMenuButtonSize,elementMenuButtonSize),1,39);
	elementMenuLayout->addItem(new QSpacerItem(elementMenuButtonSize,elementMenuButtonSize),2,39);

	namedLocationButton = new QToolButton();
	namedLocationButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseNamedLocationAct = new QAction();
	namedLocationButton->setDefaultAction(chooseNamedLocationAct);
	connect(chooseNamedLocationAct, &QAction::triggered, this, &Window::chooseNamedLocation);
	namedLocationIcon = new QIcon(":/graphics/graphics/namedLocationSet.png");
	namedLocationButton->setIcon(*namedLocationIcon);
	elementMenuLayout->addWidget(namedLocationButton, 0, 40);

	concourseButton = new QToolButton();
	concourseButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseConcourseAct = new QAction();
	concourseButton->setDefaultAction(chooseConcourseAct);
	connect(chooseConcourseAct, &QAction::triggered, this, &Window::chooseConcourse);
	concourseIcon = new QIcon(":/graphics/graphics/concourseSet.png");
	concourseButton->setIcon(*concourseIcon);
	elementMenuLayout->addWidget(concourseButton, 0, 41);

	platformUpButton = new QToolButton();
	platformUpButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	choosePlatformUpAct = new QAction();
	platformUpButton->setDefaultAction(choosePlatformUpAct);
	connect(choosePlatformUpAct, &QAction::triggered, this, &Window::choosePlatformUp);
	platformUpIcon = new QIcon(":/graphics/graphics/platformUpSet.png");
	platformUpButton->setIcon(*platformUpIcon);
	elementMenuLayout->addWidget(platformUpButton, 1, 40);

	platformDownButton = new QToolButton();
	platformDownButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	choosePlatformDownAct = new QAction();
	platformDownButton->setDefaultAction(choosePlatformDownAct);
	connect(choosePlatformDownAct, &QAction::triggered, this, &Window::choosePlatformDown);
	platformDownIcon = new QIcon(":/graphics/graphics/platformDownSet.png");
	platformDownButton->setIcon(*platformDownIcon);
	elementMenuLayout->addWidget(platformDownButton, 1, 41);

	platformLeftButton = new QToolButton();
	platformLeftButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	choosePlatformLeftAct = new QAction();
	platformLeftButton->setDefaultAction(choosePlatformLeftAct);
	connect(choosePlatformLeftAct, &QAction::triggered, this, &Window::choosePlatformLeft);
	platformLeftIcon = new QIcon(":/graphics/graphics/platformLeftSet.png");
	platformLeftButton->setIcon(*platformLeftIcon);
	elementMenuLayout->addWidget(platformLeftButton, 2, 40);

	platformRightButton = new QToolButton();
	platformRightButton->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	choosePlatformRightAct = new QAction();
	platformRightButton->setDefaultAction(choosePlatformRightAct);
	connect(choosePlatformRightAct, &QAction::triggered, this, &Window::choosePlatformRight);
	platformRightIcon = new QIcon(":/graphics/graphics/platformRightSet.png");
	platformRightButton->setIcon(*platformRightIcon);
	elementMenuLayout->addWidget(platformRightButton, 2, 41);
}

void Window::createElementBlock5()
{
	elementMenuLayout->addItem(new QSpacerItem(elementMenuButtonSize,elementMenuButtonSize),0,42);
	elementMenuLayout->addItem(new QSpacerItem(elementMenuButtonSize,elementMenuButtonSize),1,42);
	elementMenuLayout->addItem(new QSpacerItem(elementMenuButtonSize,elementMenuButtonSize),2,42);

	parapet1Button = new QToolButton();
	parapet1Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet1Act = new QAction();
	parapet1Button->setDefaultAction(chooseParapet1Act);
	connect(chooseParapet1Act, &QAction::triggered, this, &Window::chooseParapet1);
	parapet1Icon = new QIcon(":/graphics/graphics/parapet1.png");
	parapet1Button->setIcon(*parapet1Icon);
	elementMenuLayout->addWidget(parapet1Button, 0, 43);

	parapet2Button = new QToolButton();
	parapet2Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet2Act = new QAction();
	parapet2Button->setDefaultAction(chooseParapet2Act);
	connect(chooseParapet2Act, &QAction::triggered, this, &Window::chooseParapet2);
	parapet2Icon = new QIcon(":/graphics/graphics/parapet2.png");
	parapet2Button->setIcon(*parapet2Icon);
	elementMenuLayout->addWidget(parapet2Button, 0, 44);

	parapet3Button = new QToolButton();
	parapet3Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet3Act = new QAction();
	parapet3Button->setDefaultAction(chooseParapet3Act);
	connect(chooseParapet3Act, &QAction::triggered, this, &Window::chooseParapet3);
	parapet3Icon = new QIcon(":/graphics/graphics/parapet3.png");
	parapet3Button->setIcon(*parapet3Icon);
	elementMenuLayout->addWidget(parapet3Button, 0, 45);

	parapet4Button = new QToolButton();
	parapet4Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet4Act = new QAction();
	parapet4Button->setDefaultAction(chooseParapet4Act);
	connect(chooseParapet4Act, &QAction::triggered, this, &Window::chooseParapet4);
	parapet4Icon = new QIcon(":/graphics/graphics/parapet4.png");
	parapet4Button->setIcon(*parapet4Icon);
	elementMenuLayout->addWidget(parapet4Button, 0, 46);

	parapet5Button = new QToolButton();
	parapet5Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet5Act = new QAction();
	parapet5Button->setDefaultAction(chooseParapet5Act);
	connect(chooseParapet5Act, &QAction::triggered, this, &Window::chooseParapet5);
	parapet5Icon = new QIcon(":/graphics/graphics/parapet5.png");
	parapet5Button->setIcon(*parapet5Icon);
	elementMenuLayout->addWidget(parapet5Button, 0, 47);

	parapet6Button = new QToolButton();
	parapet6Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet6Act = new QAction();
	parapet6Button->setDefaultAction(chooseParapet6Act);
	connect(chooseParapet6Act, &QAction::triggered, this, &Window::chooseParapet6);
	parapet6Icon = new QIcon(":/graphics/graphics/parapet6.png");
	parapet6Button->setIcon(*parapet6Icon);
	elementMenuLayout->addWidget(parapet6Button, 0, 48);

	parapet7Button = new QToolButton();
	parapet7Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet7Act = new QAction();
	parapet7Button->setDefaultAction(chooseParapet7Act);
	connect(chooseParapet7Act, &QAction::triggered, this, &Window::chooseParapet7);
	parapet7Icon = new QIcon(":/graphics/graphics/parapet7.png");
	parapet7Button->setIcon(*parapet7Icon);
	elementMenuLayout->addWidget(parapet7Button, 0, 49);

	parapet8Button = new QToolButton();
	parapet8Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet8Act = new QAction();
	parapet8Button->setDefaultAction(chooseParapet8Act);
	connect(chooseParapet8Act, &QAction::triggered, this, &Window::chooseParapet8);
	parapet8Icon = new QIcon(":/graphics/graphics/parapet8.png");
	parapet8Button->setIcon(*parapet8Icon);
	elementMenuLayout->addWidget(parapet8Button, 0, 50);

	parapet9Button = new QToolButton();
	parapet9Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet9Act = new QAction();
	parapet9Button->setDefaultAction(chooseParapet9Act);
	connect(chooseParapet9Act, &QAction::triggered, this, &Window::chooseParapet9);
	parapet9Icon = new QIcon(":/graphics/graphics/parapet9.png");
	parapet9Button->setIcon(*parapet9Icon);
	elementMenuLayout->addWidget(parapet9Button, 0, 51);

	parapet10Button = new QToolButton();
	parapet10Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet10Act = new QAction();
	parapet10Button->setDefaultAction(chooseParapet10Act);
	connect(chooseParapet10Act, &QAction::triggered, this, &Window::chooseParapet10);
	parapet10Icon = new QIcon(":/graphics/graphics/parapet10.png");
	parapet10Button->setIcon(*parapet10Icon);
	elementMenuLayout->addWidget(parapet10Button, 0, 52);

	parapet11Button = new QToolButton();
	parapet11Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet11Act = new QAction();
	parapet11Button->setDefaultAction(chooseParapet11Act);
	connect(chooseParapet11Act, &QAction::triggered, this, &Window::chooseParapet11);
	parapet11Icon = new QIcon(":/graphics/graphics/parapet11.png");
	parapet11Button->setIcon(*parapet11Icon);
	elementMenuLayout->addWidget(parapet11Button, 1, 43);

	parapet12Button = new QToolButton();
	parapet12Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet12Act = new QAction();
	parapet12Button->setDefaultAction(chooseParapet12Act);
	connect(chooseParapet12Act, &QAction::triggered, this, &Window::chooseParapet12);
	parapet12Icon = new QIcon(":/graphics/graphics/parapet12.png");
	parapet12Button->setIcon(*parapet12Icon);
	elementMenuLayout->addWidget(parapet12Button, 1, 44);

	parapet13Button = new QToolButton();
	parapet13Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet13Act = new QAction();
	parapet13Button->setDefaultAction(chooseParapet13Act);
	connect(chooseParapet13Act, &QAction::triggered, this, &Window::chooseParapet13);
	parapet13Icon = new QIcon(":/graphics/graphics/parapet13.png");
	parapet13Button->setIcon(*parapet13Icon);
	elementMenuLayout->addWidget(parapet13Button, 1, 45);

	parapet14Button = new QToolButton();
	parapet14Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet14Act = new QAction();
	parapet14Button->setDefaultAction(chooseParapet14Act);
	connect(chooseParapet14Act, &QAction::triggered, this, &Window::chooseParapet14);
	parapet14Icon = new QIcon(":/graphics/graphics/parapet14.png");
	parapet14Button->setIcon(*parapet14Icon);
	elementMenuLayout->addWidget(parapet14Button, 1, 46);

	parapet15Button = new QToolButton();
	parapet15Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet15Act = new QAction();
	parapet15Button->setDefaultAction(chooseParapet15Act);
	connect(chooseParapet15Act, &QAction::triggered, this, &Window::chooseParapet15);
	parapet15Icon = new QIcon(":/graphics/graphics/parapet15.png");
	parapet15Button->setIcon(*parapet15Icon);
	elementMenuLayout->addWidget(parapet15Button, 1, 47);

	parapet16Button = new QToolButton();
	parapet16Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet16Act = new QAction();
	parapet16Button->setDefaultAction(chooseParapet16Act);
	connect(chooseParapet16Act, &QAction::triggered, this, &Window::chooseParapet16);
	parapet16Icon = new QIcon(":/graphics/graphics/parapet16.png");
	parapet16Button->setIcon(*parapet16Icon);
	elementMenuLayout->addWidget(parapet16Button, 1, 48);

	parapet17Button = new QToolButton();
	parapet17Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet17Act = new QAction();
	parapet17Button->setDefaultAction(chooseParapet17Act);
	connect(chooseParapet17Act, &QAction::triggered, this, &Window::chooseParapet17);
	parapet17Icon = new QIcon(":/graphics/graphics/parapet17.png");
	parapet17Button->setIcon(*parapet17Icon);
	elementMenuLayout->addWidget(parapet17Button, 1, 49);

	parapet18Button = new QToolButton();
	parapet18Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet18Act = new QAction();
	parapet18Button->setDefaultAction(chooseParapet18Act);
	connect(chooseParapet18Act, &QAction::triggered, this, &Window::chooseParapet18);
	parapet18Icon = new QIcon(":/graphics/graphics/parapet18.png");
	parapet18Button->setIcon(*parapet18Icon);
	elementMenuLayout->addWidget(parapet18Button, 1, 50);

	parapet19Button = new QToolButton();
	parapet19Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet19Act = new QAction();
	parapet19Button->setDefaultAction(chooseParapet19Act);
	connect(chooseParapet19Act, &QAction::triggered, this, &Window::chooseParapet19);
	parapet19Icon = new QIcon(":/graphics/graphics/parapet19.png");
	parapet19Button->setIcon(*parapet19Icon);
	elementMenuLayout->addWidget(parapet19Button, 1, 51);

	parapet20Button = new QToolButton();
	parapet20Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet20Act = new QAction();
	parapet20Button->setDefaultAction(chooseParapet20Act);
	connect(chooseParapet20Act, &QAction::triggered, this, &Window::chooseParapet20);
	parapet20Icon = new QIcon(":/graphics/graphics/parapet20.png");
	parapet20Button->setIcon(*parapet20Icon);
	elementMenuLayout->addWidget(parapet20Button, 1, 52);

	parapet21Button = new QToolButton();
	parapet21Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet21Act = new QAction();
	parapet21Button->setDefaultAction(chooseParapet21Act);
	connect(chooseParapet21Act, &QAction::triggered, this, &Window::chooseParapet21);
	parapet21Icon = new QIcon(":/graphics/graphics/parapet21.png");
	parapet21Button->setIcon(*parapet21Icon);
	elementMenuLayout->addWidget(parapet21Button, 2, 43);

	parapet22Button = new QToolButton();
	parapet22Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet22Act = new QAction();
	parapet22Button->setDefaultAction(chooseParapet22Act);
	connect(chooseParapet22Act, &QAction::triggered, this, &Window::chooseParapet22);
	parapet22Icon = new QIcon(":/graphics/graphics/parapet22.png");
	parapet22Button->setIcon(*parapet22Icon);
	elementMenuLayout->addWidget(parapet22Button, 2, 44);

	parapet23Button = new QToolButton();
	parapet23Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet23Act = new QAction();
	parapet23Button->setDefaultAction(chooseParapet23Act);
	connect(chooseParapet23Act, &QAction::triggered, this, &Window::chooseParapet23);
	parapet23Icon = new QIcon(":/graphics/graphics/parapet23.png");
	parapet23Button->setIcon(*parapet23Icon);
	elementMenuLayout->addWidget(parapet23Button, 2, 45);

	parapet24Button = new QToolButton();
	parapet24Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet24Act = new QAction();
	parapet24Button->setDefaultAction(chooseParapet24Act);
	connect(chooseParapet24Act, &QAction::triggered, this, &Window::chooseParapet24);
	parapet24Icon = new QIcon(":/graphics/graphics/parapet24.png");
	parapet24Button->setIcon(*parapet24Icon);
	elementMenuLayout->addWidget(parapet24Button, 2, 46);

	elementMenuLayout->addItem(new QSpacerItem(elementMenuButtonSize,elementMenuButtonSize),2,47);

	parapet25Button = new QToolButton();
	parapet25Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet25Act = new QAction();
	parapet25Button->setDefaultAction(chooseParapet25Act);
	connect(chooseParapet25Act, &QAction::triggered, this, &Window::chooseParapet25);
	parapet25Icon = new QIcon(":/graphics/graphics/parapet25.png");
	parapet25Button->setIcon(*parapet25Icon);
	elementMenuLayout->addWidget(parapet25Button, 2, 48);

	parapet26Button = new QToolButton();
	parapet26Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet26Act = new QAction();
	parapet26Button->setDefaultAction(chooseParapet26Act);
	connect(chooseParapet26Act, &QAction::triggered, this, &Window::chooseParapet26);
	parapet26Icon = new QIcon(":/graphics/graphics/parapet26.png");
	parapet26Button->setIcon(*parapet26Icon);
	elementMenuLayout->addWidget(parapet26Button, 2, 49);

	parapet27Button = new QToolButton();
	parapet27Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet27Act = new QAction();
	parapet27Button->setDefaultAction(chooseParapet27Act);
	connect(chooseParapet27Act, &QAction::triggered, this, &Window::chooseParapet27);
	parapet27Icon = new QIcon(":/graphics/graphics/parapet27.png");
	parapet27Button->setIcon(*parapet27Icon);
	elementMenuLayout->addWidget(parapet27Button, 2, 50);

	parapet28Button = new QToolButton();
	parapet28Button->setMaximumSize(QSize(elementMenuButtonSize, elementMenuButtonSize));
	chooseParapet28Act = new QAction();
	parapet28Button->setDefaultAction(chooseParapet28Act);
	connect(chooseParapet28Act, &QAction::triggered, this, &Window::chooseParapet28);
	parapet28Icon = new QIcon(":/graphics/graphics/parapet28.png");
	parapet28Button->setIcon(*parapet28Icon);
	elementMenuLayout->addWidget(parapet28Button, 2, 51);
}

void Window::createElementBlock6()
{
	elementMenuLayout->addItem(new QSpacerItem(elementMenuButtonSize,elementMenuButtonSize),0,52);
	elementMenuLayout->addItem(new QSpacerItem(elementMenuButtonSize,elementMenuButtonSize),1,52);
	elementMenuLayout->addItem(new QSpacerItem(elementMenuButtonSize,elementMenuButtonSize),2,52);


	levelCrossingButton = new QToolButton();
	levelCrossingButton->setMaximumSize(QSize(32, 32));
	chooseLevelCrossingAct = new QAction();
	levelCrossingButton->setDefaultAction(chooseLevelCrossingAct);
	connect(chooseLevelCrossingAct, &QAction::triggered, this, &Window::chooseLevelCrossing);
	levelCrossingIcon = new QIcon(":/graphics/graphics/levelCrossingIcon.png");
	levelCrossingButton->setIcon(*levelCrossingIcon);
	//levelCrossingButton->setAutoRaise(true);
	elementMenuLayout->addWidget(levelCrossingButton, 2, 53);
}

	//SetConvertSpeedDistanceMenu

void Window::createSetConvertSpeedDistanceMenu()
{
	//Overall
	setConvertSpeedDistanceMenu = new QWidget;
	setConvertSpeedDistanceHLayout = new QHBoxLayout;
	setConvertSpeedDistanceMenu->setLayout(setConvertSpeedDistanceHLayout);

	//Converting distances menu.
	keyGraphicImage = new QLabel;
	keyImage = new QImage(":/icons/icons/keyGraphic.png");
	keyGraphicImage->setPixmap(QPixmap::fromImage(*keyImage));
	keyGraphicImage->setScaledContents(true);
	keyGraphicImage->setMaximumHeight(120);
	keyGraphicImage->setMaximumWidth(500);
	setConvertSpeedDistanceHLayout->addWidget(keyGraphicImage);

	converterGrid1 = new QGridLayout;
	milesLabel = new QLabel;
	milesLabel->setText(tr("Miles"));
	milesEntry = new QLineEdit;
	milesEntry->setMaximumWidth(120);
	chainsLabel = new QLabel;
	chainsLabel->setText(tr("chains"));
	chainsEntry = new QLineEdit;
	chainsEntry->setMaximumWidth(120);
	yardsLabel = new QLabel;
	yardsLabel->setText(tr("Yards"));
	yardsEntry = new QLineEdit;
	yardsEntry->setMaximumWidth(120);
	metresLabel = new QLabel;
	metresLabel->setText(tr("Metres"));
	actualMetres = new QLineEdit;
	actualMetres->setMaximumWidth(120);
	actualMetres->setReadOnly(true);
	actualMetres->setDisabled(true);

	connect(milesEntry, &QLineEdit::textChanged, this, &Window::updateMilesChainsYardsToMetresGUI);
	connect(chainsEntry, &QLineEdit::textChanged, this, &Window::updateMilesChainsYardsToMetresGUI);
	connect(yardsEntry, &QLineEdit::textChanged, this, &Window::updateMilesChainsYardsToMetresGUI);

	converterGrid1->addWidget(milesLabel,0,1);
	converterGrid1->addWidget(milesEntry,0,0);
	converterGrid1->addWidget(chainsLabel,1,1);
	converterGrid1->addWidget(chainsEntry,1,0);
	converterGrid1->addWidget(yardsLabel,2,1);
	converterGrid1->addWidget(yardsEntry,2,0);

	converterGrid1->addWidget(metresLabel,0,2);
	converterGrid1->addWidget(actualMetres,1,2);

	//Converting speed menu.
	converterGrid2 = new QGridLayout;
	speedLabel1 = new QLabel;
	speedLabel1->setText(tr("mph"));
	speedEntry1 = new QLineEdit;

	speedEntry1->setMaximumWidth(120);
	swapLabelButton = new QPushButton;
	swapLabelButton->setText(tr("Swap"));
	swapLabelButton->setMinimumWidth(30);
	swapLabelButton->setMaximumWidth(75);
	connect(swapLabelButton, SIGNAL (released()),this, SLOT (swapSpeedLabel()));
	speedLabel2 = new QLabel;
	speedLabel2->setText(tr("km/h"));
	speedResult = new QLineEdit;
	speedResult->setMaximumWidth(120);
	speedResult->setDisabled(true);
	connect(speedEntry1, &QLineEdit::textChanged, this, &Window::updateMPHKMHGUI);

	converterGrid2->addWidget(speedLabel1,0,0);
	converterGrid2->addWidget(speedEntry1,1,0);
	converterGrid2->addWidget(speedLabel2,2,0);
	converterGrid2->addWidget(swapLabelButton,2,1);
	converterGrid2->addWidget(speedResult,3,0);
	converterGrid2->setVerticalSpacing(1);


	setConvertSpeedDistanceHLayout->setAlignment(converterGrid2, Qt::AlignLeft);

	setConvertSpeedDistanceHLayout->addLayout(converterGrid1);
	setConvertSpeedDistanceHLayout->addLayout(converterGrid2);
}

double Window::getMilesFromGUIToConvert()
{
	/* If the miles text entry isn't empty, try make it a double.
	 * Then make it equal to the double that was inputted by the user.
	 * Otherwise make miles = 0.
	 */
	double miles = 0;
	if (!milesEntry->text().isEmpty())
	{

		bool ok = false;
		double tempD = milesEntry->text().toDouble(&ok);
		if (ok)
		{
			 miles = tempD;
		}
	}
	return miles;
}

double Window::getChainsFromGUIToConvert()
{
	/* If the chains text entry isn't empty, try make it a double.
	 * Then make it equal to the double that was inputted by the user.
	 * Otherwise make chains = 0.
	 */
	double chains = 0;
	if (!chainsEntry->text().isEmpty())
	{
		bool ok = false;
		double tempD = chainsEntry->text().toDouble(&ok);
		if (ok)
		{
			 chains = tempD;
		}
	}
	return chains;
}

double Window::getYardsFromGUIToConvert()
{
	/* If the yards text entry isn't empty, try make it a double.
	 * Then make it equal to the double that was inputted by the user.
	 * Otherwise make yards = 0.
	 */
	double yards = 0;
	if (!yardsEntry->text().isEmpty())
	{
		bool ok = false;
		double tempD = yardsEntry->text().toDouble(&ok);
		if (ok)
		{
			 yards = tempD;
		}
	}
	return yards;
}

double Window::getSpeedFromGUIToConvert()
{
	double speed = 0;

	if (!speedEntry1->text().isEmpty())
	{
		bool ok = false;
		//If a speed is entered, try convert it to a double.
		double tempD = speedEntry1->text().toDouble(&ok);
		if (ok)
		{
			speed = tempD;
		}
	}
	return speed;
}

double Window::convertMilesToMetres(double miles)
{
	return miles * MILE_FACTOR;
}

double Window::convertChainsToMetres(double chains)
{
	return chains * CHAIN_FACTOR;
}

double Window::convertYardsToMetres(double yards)
{
	return yards * YARD_FACTOR;
}

double Window::convertMPHToKMPH(double mph)
{
	return mph * MPH_TO_KMPH;
}

double Window::convertKMPHToMPH(double kmph)
{
	return kmph / MPH_TO_KMPH;
}

	//Right side directional menu.

void Window::createRightDirectionalMenu()
{
	rightDirectionalMenu = new QWidget;

	rightDirectionalMenuLayout = new QVBoxLayout;
	rightDirectionalMenu->setLayout(rightDirectionalMenuLayout);

	canvasMoveRightButton = new QToolButton();
	canvasMoveRightButton->setMaximumSize(QSize(32, 32));
	canvasMoveRightAct = new QAction();
	canvasMoveRightButton->setDefaultAction(canvasMoveRightAct);
	connect(canvasMoveRightAct, &QAction::triggered, this, &Window::moveRightOnCanvas);
	canvasMoveRightIcon = new QIcon(":/icons/icons/right.png");
	canvasMoveRightButton->setIcon(*canvasMoveRightIcon);
	rightDirectionalMenuLayout->addWidget(canvasMoveRightButton);

	canvasMoveLeftButton = new QToolButton();
	canvasMoveLeftButton->setMaximumSize(QSize(32, 32));
	canvasMoveLeftAct = new QAction();
	canvasMoveLeftButton->setDefaultAction(canvasMoveLeftAct);
	connect(canvasMoveLeftAct, &QAction::triggered, this, &Window::moveLeftOnCanvas);
	canvasMoveLeftIcon = new QIcon(":/icons/icons/left.png");
	canvasMoveLeftButton->setIcon(*canvasMoveLeftIcon);
	rightDirectionalMenuLayout->addWidget(canvasMoveLeftButton);

	canvasMoveUpButton = new QToolButton();
	canvasMoveUpButton->setMaximumSize(QSize(32, 32));
	canvasMoveUpAct = new QAction();
	canvasMoveUpButton->setDefaultAction(canvasMoveUpAct);
	connect(canvasMoveUpAct, &QAction::triggered, this, &Window::moveUpOnCanvas);
	canvasMoveUpIcon = new QIcon(":/icons/icons/up.png");
	canvasMoveUpButton->setIcon(*canvasMoveUpIcon);
	rightDirectionalMenuLayout->addWidget(canvasMoveUpButton);

	canvasMoveDownButton = new QToolButton();
	canvasMoveDownButton->setMaximumSize(QSize(32, 32));
	canvasMoveDownAct = new QAction();
	canvasMoveDownButton->setDefaultAction(canvasMoveDownAct);
	connect(canvasMoveDownAct, &QAction::triggered, this, &Window::moveDownOnCanvas);
	canvasMoveDownIcon = new QIcon(":/icons/icons/down.png");
	canvasMoveDownButton->setIcon(*canvasMoveDownIcon);
	rightDirectionalMenuLayout->addWidget(canvasMoveDownButton);
}

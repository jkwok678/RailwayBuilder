#include "window.h"

//Public

Window::Window()
{
	drawingArea = new Canvas;
	createMenuBar();
	createOverallMenu();
	createRightDirectionalMenu();
	mode = Mode::NONE;
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

void Window::openElementMenu()
{
	//Set the QStackWidget to the AddMoveTrack menu if it isn't on there yet.
	//If it is, then go back to the start.
	if (allMenus->currentIndex() != 1)
	{
		allMenus->setCurrentIndex(1);
		mode = Mode::ADDREMOVETRACK;
	}
	else
	{
		allMenus->setCurrentIndex(0);
		mode = Mode::NONE;
	}

}

void Window::openSetConvertSpeedDistanceMenu()
{
	//Set the QStackWidget to the setConvertSpeedDistance menu if it isn't on there yet.
	//If it is, then go back to the start.
	if (allMenus->currentIndex() != 2)
	{
		allMenus->setCurrentIndex(2);
		mode = Mode::SETCONVERTSPEEDDISTANCE;
	}
	else
	{
		allMenus->setCurrentIndex(0);
		mode = Mode::NONE;
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

//Element menu to choose element

void Window::chooseStraightH()
{
	//If the Mode is AddRemoveTrack and the element is StraightH,
	// the element to add will be a Straight horizontal.
	//Otherwise set to nothing.
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::STRAIGHTH)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::STRAIGHTV)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::DIRECTEDLEFT)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::DIRECTEDRIGHT)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::DIRECTEDUP)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::DIRECTEDDOWN)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::STRAIGHTLEFTUP)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::STRAIGHTRIGHTUP)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::DIRECTEDLEFTUP)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::DIRECTEDRIGHTUP)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::DIRECTEDLEFTDOWN)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::DIRECTEDRIGHTDOWN)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::TIGHTCURVE1)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::TIGHTCURVE2)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::TIGHTCURVE3)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::TIGHTCURVE4)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CURVE1)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CURVE2)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CURVE3)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CURVE4)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::LINKLEFT)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::LINKRIGHT)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::LINKDOWN)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::LINKUP)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::LINKLEFTUP)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::LINKRIGHTUP)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::LINKLEFTDOWN)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::LINKRIGHTDOWN)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::EXITLEFT)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::EXITRIGHT)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::EXITDOWN)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::EXITUP)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::EXITLEFTUP)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::EXITRIGHT)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::EXITLEFTDOWN)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::EXITRIGHTDOWN)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CURVE5)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CURVE6)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CURVE7)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::CURVE8)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BUFFERLEFT)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BUFFERRIGHT)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BUFFERDOWN)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BUFFERUP)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BUFFERLEFTUP)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BUFFERRIGHTUP)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BUFFERLEFTDOWN)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BUFFERRIGHTDOWN)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SIGNALLEFT)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SIGNALRIGHT)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SIGNALDOWN)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SIGNALUP)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SIGNALLEFTUP)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SIGNALRIGHTUP)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SIGNALLEFTDOWN)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::SIGNALRIGHTDOWN)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BRIDGE1)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::BRIDGE2)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::UNDERPASS1)
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
	if (mode==Mode::ADDREMOVETRACK && drawingArea->getElementChosen() != ElementChosen::UNDERPASS2)
	{
		drawingArea->setElementChosen(ElementChosen::UNDERPASS2);
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
	menuBar->addMenu(fileMenu);
	menuBar->addMenu(modeMenu);
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
	elementMenu->setLayout(elementMenuLayout);
	createElementBlock1();
}

void Window::createElementBlock1()
{
	straightHButton = new QToolButton();
	straightHButton->setMaximumSize(QSize(32, 32));
	chooseStraightHAct = new QAction();
	straightHButton->setDefaultAction(chooseStraightHAct);
	connect(chooseStraightHAct, &QAction::triggered, this, &Window::chooseStraightH);
	straightHIcon = new QIcon(":/graphics/graphics/straightH.png");
	straightHButton->setIcon(*straightHIcon);
	elementMenuLayout->addWidget(straightHButton, 0, 0);

	straightVButton = new QToolButton();
		straightVButton->setMaximumSize(QSize(32, 32));
		chooseStraightVAct = new QAction();
		straightVButton->setDefaultAction(chooseStraightVAct);
		connect(chooseStraightVAct, &QAction::triggered, this, &Window::chooseStraightV);
		straightVIcon = new QIcon(":/graphics/graphics/straightV.png");
		straightVButton->setIcon(*straightVIcon);
		elementMenuLayout->addWidget(straightVButton, 0, 1);

		directedLeftButton = new QToolButton();
		directedLeftButton->setMaximumSize(QSize(32, 32));
		chooseDirectedLeftAct = new QAction();
		directedLeftButton->setDefaultAction(chooseDirectedLeftAct);
		connect(chooseDirectedLeftAct, &QAction::triggered, this, &Window::chooseDirectedLeft);
		directedLeftIcon = new QIcon(":/graphics/graphics/directLeft.png");
		directedLeftButton->setIcon(*directedLeftIcon);
		elementMenuLayout->addWidget(directedLeftButton, 0, 2);

		directedRightButton = new QToolButton();
		directedRightButton->setMaximumSize(QSize(32, 32));
		chooseDirectedRightAct = new QAction();
		directedRightButton->setDefaultAction(chooseDirectedRightAct);
		connect(chooseDirectedRightAct, &QAction::triggered, this, &Window::chooseDirectedRight);
		directedRightIcon = new QIcon(":/graphics/graphics/directRight.png");
		directedRightButton->setIcon(*directedRightIcon);
		elementMenuLayout->addWidget(directedRightButton, 0, 3);

		directedUpButton = new QToolButton();
		directedUpButton->setMaximumSize(QSize(32, 32));
		chooseDirectedUpAct = new QAction();
		directedUpButton->setDefaultAction(chooseDirectedUpAct);
		connect(chooseDirectedUpAct, &QAction::triggered, this, &Window::chooseDirectedUp);
		directedUpIcon = new QIcon(":/graphics/graphics/directUp.png");
		directedUpButton->setIcon(*directedUpIcon);
		elementMenuLayout->addWidget(directedUpButton, 0, 4);

		directedDownButton = new QToolButton();
		directedDownButton->setMaximumSize(QSize(32, 32));
		chooseDirectedDownAct = new QAction();
		directedDownButton->setDefaultAction(chooseDirectedDownAct);
		connect(chooseDirectedDownAct, &QAction::triggered, this, &Window::chooseDirectedDown);
		directedDownIcon = new QIcon(":/graphics/graphics/directDown.png");
		directedDownButton->setIcon(*directedDownIcon);
		elementMenuLayout->addWidget(directedDownButton, 0, 5);

		straightRightUpButton = new QToolButton();
		straightRightUpButton->setMaximumSize(QSize(32, 32));
		chooseStraightRightUpAct = new QAction();
		straightRightUpButton->setDefaultAction(chooseStraightRightUpAct);
		connect(chooseStraightRightUpAct, &QAction::triggered, this, &Window::chooseStraightRightUp);
		straightRightUpIcon = new QIcon(":/graphics/graphics/straightRightUp.png");
		straightRightUpButton->setIcon(*straightRightUpIcon);
		elementMenuLayout->addWidget(straightRightUpButton, 0, 6);

		straightLeftUpButton = new QToolButton();
		straightLeftUpButton->setMaximumSize(QSize(32, 32));
		chooseStraightLeftUpAct = new QAction();
		straightLeftUpButton->setDefaultAction(chooseStraightLeftUpAct);
		connect(chooseStraightLeftUpAct, &QAction::triggered, this, &Window::chooseStraightLeftUp);
		straightLeftUpIcon = new QIcon(":/graphics/graphics/straightLeftUp.png");
		straightLeftUpButton->setIcon(*straightLeftUpIcon);
		elementMenuLayout->addWidget(straightLeftUpButton, 0, 7);

		directedRightUpButton = new QToolButton();
		directedRightUpButton->setMaximumSize(QSize(32, 32));
		chooseDirectedRightUpAct = new QAction();
		directedRightUpButton->setDefaultAction(chooseDirectedRightUpAct);
		connect(chooseDirectedRightUpAct, &QAction::triggered, this, &Window::chooseDirectedRightUp);
		directedRightUpIcon = new QIcon(":/graphics/graphics/directRightUp.png");
		directedRightUpButton->setIcon(*directedRightUpIcon);
		elementMenuLayout->addWidget(directedRightUpButton, 0, 8);

		directedLeftUpButton = new QToolButton();
		directedLeftUpButton->setMaximumSize(QSize(32, 32));
		chooseDirectedLeftUpAct = new QAction();
		directedLeftUpButton->setDefaultAction(chooseDirectedLeftUpAct);
		connect(chooseDirectedLeftUpAct, &QAction::triggered, this, &Window::chooseDirectedLeftUp);
		directedLeftUpIcon = new QIcon(":/graphics/graphics/directLeftUp.png");
		directedLeftUpButton->setIcon(*directedLeftUpIcon);
		elementMenuLayout->addWidget(directedLeftUpButton, 0, 9);

		directedLeftDownButton = new QToolButton();
		directedLeftDownButton->setMaximumSize(QSize(32, 32));
		chooseDirectedLeftDownAct = new QAction();
		directedLeftDownButton->setDefaultAction(chooseDirectedLeftDownAct);
		connect(chooseDirectedLeftDownAct, &QAction::triggered, this, &Window::chooseDirectedLeftDown);
		directedLeftDownIcon = new QIcon(":/graphics/graphics/directLeftDown.png");
		directedLeftDownButton->setIcon(*directedLeftDownIcon);
		elementMenuLayout->addWidget(directedLeftDownButton, 0, 10);

		directedRightDownButton = new QToolButton();
		directedRightDownButton->setMaximumSize(QSize(32, 32));
		chooseDirectedRightDownAct = new QAction();
		directedRightDownButton->setDefaultAction(chooseDirectedRightDownAct);
		connect(chooseDirectedRightDownAct, &QAction::triggered, this, &Window::chooseDirectedRightDown);
		directedRightDownIcon = new QIcon(":/graphics/graphics/directRightDown.png");
		directedRightDownButton->setIcon(*directedRightDownIcon);
		elementMenuLayout->addWidget(directedRightDownButton, 0, 11);

		tightCurve1Button = new QToolButton();
		tightCurve1Button->setMaximumSize(QSize(32, 32));
		chooseTightCurve1Act = new QAction();
		tightCurve1Button->setDefaultAction(chooseTightCurve1Act);
		connect(chooseTightCurve1Act, &QAction::triggered, this, &Window::chooseTightCurve1);
		tightCurve1Icon = new QIcon(":/graphics/graphics/tightCurve1.png");
		tightCurve1Button->setIcon(*tightCurve1Icon);
		elementMenuLayout->addWidget(tightCurve1Button, 0, 12);

		tightCurve2Button = new QToolButton();
		tightCurve2Button->setMaximumSize(QSize(32, 32));
		chooseTightCurve2Act = new QAction();
		tightCurve2Button->setDefaultAction(chooseTightCurve2Act);
		connect(chooseTightCurve2Act, &QAction::triggered, this, &Window::chooseTightCurve2);
		tightCurve2Icon = new QIcon(":/graphics/graphics/tightCurve2.png");
		tightCurve2Button->setIcon(*tightCurve2Icon);
		elementMenuLayout->addWidget(tightCurve2Button, 0, 13);

		tightCurve3Button = new QToolButton();
		tightCurve3Button->setMaximumSize(QSize(32, 32));
		chooseTightCurve3Act = new QAction();
		tightCurve3Button->setDefaultAction(chooseTightCurve3Act);
		connect(chooseTightCurve3Act, &QAction::triggered, this, &Window::chooseTightCurve3);
		tightCurve3Icon = new QIcon(":/graphics/graphics/tightCurve3.png");
		tightCurve3Button->setIcon(*tightCurve3Icon);
		elementMenuLayout->addWidget(tightCurve3Button, 0, 14);

		tightCurve4Button = new QToolButton();
		tightCurve4Button->setMaximumSize(QSize(32, 32));
		chooseTightCurve4Act = new QAction();
		tightCurve4Button->setDefaultAction(chooseTightCurve4Act);
		connect(chooseTightCurve4Act, &QAction::triggered, this, &Window::chooseTightCurve4);
		tightCurve4Icon = new QIcon(":/graphics/graphics/tightCurve4.png");
		tightCurve4Button->setIcon(*tightCurve4Icon);
		elementMenuLayout->addWidget(tightCurve4Button, 0, 15);

		curve1Button = new QToolButton();
		curve1Button->setMaximumSize(QSize(32, 32));
		chooseCurve1Act = new QAction();
		curve1Button->setDefaultAction(chooseCurve1Act);
		connect(chooseCurve1Act, &QAction::triggered, this, &Window::chooseCurve1);
		curve1Icon = new QIcon(":/graphics/graphics/curve1.png");
		curve1Button->setIcon(*curve1Icon);
		elementMenuLayout->addWidget(curve1Button, 0, 16);

		curve2Button = new QToolButton();
		curve2Button->setMaximumSize(QSize(32, 32));
		chooseCurve2Act = new QAction();
		curve2Button->setDefaultAction(chooseCurve2Act);
		connect(chooseCurve2Act, &QAction::triggered, this, &Window::chooseCurve2);
		curve2Icon = new QIcon(":/graphics/graphics/curve2.png");
		curve2Button->setIcon(*curve2Icon);
		elementMenuLayout->addWidget(curve2Button, 0, 17);

		curve3Button = new QToolButton();
		curve3Button->setMaximumSize(QSize(32, 32));
		chooseCurve3Act = new QAction();
		curve3Button->setDefaultAction(chooseCurve3Act);
		connect(chooseCurve3Act, &QAction::triggered, this, &Window::chooseCurve3);
		curve3Icon = new QIcon(":/graphics/graphics/curve3.png");
		curve3Button->setIcon(*curve3Icon);
		elementMenuLayout->addWidget(curve3Button, 0, 18);

		curve4Button = new QToolButton();
		curve4Button->setMaximumSize(QSize(32, 32));
		chooseCurve4Act = new QAction();
		curve4Button->setDefaultAction(chooseCurve4Act);
		connect(chooseCurve4Act, &QAction::triggered, this, &Window::chooseCurve4);
		curve4Icon = new QIcon(":/graphics/graphics/curve4.png");
		curve4Button->setIcon(*curve4Icon);
		elementMenuLayout->addWidget(curve4Button, 0, 19);

		linkLeftButton = new QToolButton();
		linkLeftButton->setMaximumSize(QSize(32, 32));
		chooseLinkLeftAct = new QAction();
		linkLeftButton->setDefaultAction(chooseLinkLeftAct);
		connect(chooseLinkLeftAct, &QAction::triggered, this, &Window::chooseLinkLeft);
		linkLeftIcon = new QIcon(":/graphics/graphics/linkLeftSet.png");
		linkLeftButton->setIcon(*linkLeftIcon);
		elementMenuLayout->addWidget(linkLeftButton, 1, 0);

		linkRightButton = new QToolButton();
		linkRightButton->setMaximumSize(QSize(32, 32));
		chooseLinkRightAct = new QAction();
		linkRightButton->setDefaultAction(chooseLinkRightAct);
		connect(chooseLinkRightAct, &QAction::triggered, this, &Window::chooseLinkRight);
		linkRightIcon = new QIcon(":/graphics/graphics/linkRightSet.png");
		linkRightButton->setIcon(*linkRightIcon);
		elementMenuLayout->addWidget(linkRightButton, 1, 1);

		linkDownButton = new QToolButton();
		linkDownButton->setMaximumSize(QSize(32, 32));
		chooseLinkDownAct = new QAction();
		linkDownButton->setDefaultAction(chooseLinkDownAct);
		connect(chooseLinkDownAct, &QAction::triggered, this, &Window::chooseLinkDown);
		linkDownIcon = new QIcon(":/graphics/graphics/linkDownSet.png");
		linkDownButton->setIcon(*linkDownIcon);
		elementMenuLayout->addWidget(linkDownButton, 1, 2);

		linkUpButton = new QToolButton();
		linkUpButton->setMaximumSize(QSize(32, 32));
		chooseLinkUpAct = new QAction();
		linkUpButton->setDefaultAction(chooseLinkUpAct);
		connect(chooseLinkUpAct, &QAction::triggered, this, &Window::chooseLinkUp);
		linkUpIcon = new QIcon(":/graphics/graphics/linkUpSet.png");
		linkUpButton->setIcon(*linkUpIcon);
		elementMenuLayout->addWidget(linkUpButton, 1, 3);

		linkLeftUpButton = new QToolButton();
		linkLeftUpButton->setMaximumSize(QSize(32, 32));
		chooseLinkLeftUpAct = new QAction();
		linkLeftUpButton->setDefaultAction(chooseLinkLeftUpAct);
		connect(chooseLinkLeftUpAct, &QAction::triggered, this, &Window::chooseLinkLeftUp);
		linkLeftUpIcon = new QIcon(":/graphics/graphics/linkLeftUpSet.png");
		linkLeftUpButton->setIcon(*linkLeftUpIcon);
		elementMenuLayout->addWidget(linkLeftUpButton, 1, 4);

		linkRightUpButton = new QToolButton();
		linkRightUpButton->setMaximumSize(QSize(32, 32));
		chooseLinkRightUpAct = new QAction();
		linkRightUpButton->setDefaultAction(chooseLinkRightUpAct);
		connect(chooseLinkRightUpAct, &QAction::triggered, this, &Window::chooseLinkRightUp);
		linkRightUpIcon = new QIcon(":/graphics/graphics/linkRightUpSet.png");
		linkRightUpButton->setIcon(*linkRightUpIcon);
		elementMenuLayout->addWidget(linkRightUpButton, 1, 5);

		linkLeftDownButton = new QToolButton();
		linkLeftDownButton->setMaximumSize(QSize(32, 32));
		chooseLinkLeftDownAct = new QAction();
		linkLeftDownButton->setDefaultAction(chooseLinkLeftDownAct);
		connect(chooseLinkLeftDownAct, &QAction::triggered, this, &Window::chooseLinkLeftDown);
		linkLeftDownIcon = new QIcon(":/graphics/graphics/linkLeftDownSet.png");
		linkLeftDownButton->setIcon(*linkLeftDownIcon);
		elementMenuLayout->addWidget(linkLeftDownButton, 1, 6);

		linkRightDownButton = new QToolButton();
		linkRightDownButton->setMaximumSize(QSize(32, 32));
		chooseLinkRightDownAct = new QAction();
		linkRightDownButton->setDefaultAction(chooseLinkRightDownAct);
		connect(chooseLinkRightDownAct, &QAction::triggered, this, &Window::chooseLinkRightDown);
		linkRightDownIcon = new QIcon(":/graphics/graphics/linkRightDownSet.png");
		linkRightDownButton->setIcon(*linkRightDownIcon);
		elementMenuLayout->addWidget(linkRightDownButton, 1, 7);

		exitLeftButton = new QToolButton();
		exitLeftButton->setMaximumSize(QSize(32, 32));
		chooseExitLeftAct = new QAction();
		exitLeftButton->setDefaultAction(chooseExitLeftAct);
		connect(chooseExitLeftAct, &QAction::triggered, this, &Window::chooseExitLeft);
		exitLeftIcon = new QIcon(":/graphics/graphics/exitLeft.png");
		exitLeftButton->setIcon(*exitLeftIcon);
		elementMenuLayout->addWidget(exitLeftButton, 1, 8);

		exitRightButton = new QToolButton();
		exitRightButton->setMaximumSize(QSize(32, 32));
		chooseExitRightAct = new QAction();
		exitRightButton->setDefaultAction(chooseExitRightAct);
		connect(chooseExitRightAct, &QAction::triggered, this, &Window::chooseExitRight);
		exitRightIcon = new QIcon(":/graphics/graphics/exitRight.png");
		exitRightButton->setIcon(*exitRightIcon);
		elementMenuLayout->addWidget(exitRightButton, 1, 9);

		exitDownButton = new QToolButton();
		exitDownButton->setMaximumSize(QSize(32, 32));
		chooseExitDownAct = new QAction();
		exitDownButton->setDefaultAction(chooseExitDownAct);
		connect(chooseExitDownAct, &QAction::triggered, this, &Window::chooseExitDown);
		exitDownIcon = new QIcon(":/graphics/graphics/exitDown.png");
		exitDownButton->setIcon(*exitDownIcon);
		elementMenuLayout->addWidget(exitDownButton, 1, 10);

		exitUpButton = new QToolButton();
		exitUpButton->setMaximumSize(QSize(32, 32));
		chooseExitUpAct = new QAction();
		exitUpButton->setDefaultAction(chooseExitUpAct);
		connect(chooseExitUpAct, &QAction::triggered, this, &Window::chooseExitUp);
		exitUpIcon = new QIcon(":/graphics/graphics/exitUp.png");
		exitUpButton->setIcon(*exitUpIcon);
		elementMenuLayout->addWidget(exitUpButton, 1, 11);

		exitLeftUpButton = new QToolButton();
		exitLeftUpButton->setMaximumSize(QSize(32, 32));
		chooseExitLeftUpAct = new QAction();
		exitLeftUpButton->setDefaultAction(chooseExitLeftUpAct);
		connect(chooseExitLeftUpAct, &QAction::triggered, this, &Window::chooseExitLeftUp);
		exitLeftUpIcon = new QIcon(":/graphics/graphics/exitLeftUp.png");
		exitLeftUpButton->setIcon(*exitLeftUpIcon);
		elementMenuLayout->addWidget(exitLeftUpButton, 1, 12);

		exitRightUpButton = new QToolButton();
		exitRightUpButton->setMaximumSize(QSize(32, 32));
		chooseExitRightUpAct = new QAction();
		exitRightUpButton->setDefaultAction(chooseExitRightUpAct);
		connect(chooseExitRightUpAct, &QAction::triggered, this, &Window::chooseExitRightUp);
		exitRightUpIcon = new QIcon(":/graphics/graphics/exitRightUp.png");
		exitRightUpButton->setIcon(*exitRightUpIcon);
		elementMenuLayout->addWidget(exitRightUpButton, 1, 13);

		exitLeftDownButton = new QToolButton();
		exitLeftDownButton->setMaximumSize(QSize(32, 32));
		chooseExitLeftDownAct = new QAction();
		exitLeftDownButton->setDefaultAction(chooseExitLeftDownAct);
		connect(chooseExitLeftDownAct, &QAction::triggered, this, &Window::chooseExitLeftDown);
		exitLeftDownIcon = new QIcon(":/graphics/graphics/exitLeftDown.png");
		exitLeftDownButton->setIcon(*exitLeftDownIcon);
		elementMenuLayout->addWidget(exitLeftDownButton, 1, 14);

		exitRightDownButton = new QToolButton();
		exitRightDownButton->setMaximumSize(QSize(32, 32));
		chooseExitRightDownAct = new QAction();
		exitRightDownButton->setDefaultAction(chooseExitRightDownAct);
		connect(chooseExitRightDownAct, &QAction::triggered, this, &Window::chooseExitRightDown);
		exitRightDownIcon = new QIcon(":/graphics/graphics/exitRightDown.png");
		exitRightDownButton->setIcon(*exitRightDownIcon);
		elementMenuLayout->addWidget(exitRightDownButton, 1, 15);

		curve5Button = new QToolButton();
		curve5Button->setMaximumSize(QSize(32, 32));
		chooseCurve5Act = new QAction();
		curve5Button->setDefaultAction(chooseCurve5Act);
		connect(chooseCurve5Act, &QAction::triggered, this, &Window::chooseCurve5);
		curve5Icon = new QIcon(":/graphics/graphics/curve5.png");
		curve5Button->setIcon(*curve5Icon);
		elementMenuLayout->addWidget(curve5Button, 1, 16);

		curve6Button = new QToolButton();
		curve6Button->setMaximumSize(QSize(32, 32));
		chooseCurve6Act = new QAction();
		curve6Button->setDefaultAction(chooseCurve6Act);
		connect(chooseCurve6Act, &QAction::triggered, this, &Window::chooseCurve6);
		curve6Icon = new QIcon(":/graphics/graphics/curve6.png");
		curve6Button->setIcon(*curve6Icon);
		elementMenuLayout->addWidget(curve6Button, 1, 17);

		curve7Button = new QToolButton();
		curve7Button->setMaximumSize(QSize(32, 32));
		chooseCurve7Act = new QAction();
		curve7Button->setDefaultAction(chooseCurve7Act);
		connect(chooseCurve7Act, &QAction::triggered, this, &Window::chooseCurve7);
		curve7Icon = new QIcon(":/graphics/graphics/curve7.png");
		curve7Button->setIcon(*curve7Icon);
		elementMenuLayout->addWidget(curve7Button, 1, 18);

		curve8Button = new QToolButton();
		curve8Button->setMaximumSize(QSize(32, 32));
		chooseCurve8Act = new QAction();
		curve8Button->setDefaultAction(chooseCurve8Act);
		connect(chooseCurve8Act, &QAction::triggered, this, &Window::chooseCurve8);
		curve8Icon = new QIcon(":/graphics/graphics/curve8.png");
		curve8Button->setIcon(*curve8Icon);
		elementMenuLayout->addWidget(curve8Button, 1, 19);

		bufferLeftButton = new QToolButton();
		bufferLeftButton->setMaximumSize(QSize(32, 32));
		chooseBufferLeftAct = new QAction();
		bufferLeftButton->setDefaultAction(chooseBufferLeftAct);
		connect(chooseBufferLeftAct, &QAction::triggered, this, &Window::chooseBufferLeft);
		bufferLeftIcon = new QIcon(":/graphics/graphics/bufferLeft.png");
		bufferLeftButton->setIcon(*bufferLeftIcon);
		elementMenuLayout->addWidget(bufferLeftButton, 2, 0);

		bufferRightButton = new QToolButton();
		bufferRightButton->setMaximumSize(QSize(32, 32));
		chooseBufferRightAct = new QAction();
		bufferRightButton->setDefaultAction(chooseBufferRightAct);
		connect(chooseBufferRightAct, &QAction::triggered, this, &Window::chooseBufferRight);
		bufferRightIcon = new QIcon(":/graphics/graphics/bufferRight.png");
		bufferRightButton->setIcon(*bufferRightIcon);
		elementMenuLayout->addWidget(bufferRightButton, 2, 1);

		bufferDownButton = new QToolButton();
		bufferDownButton->setMaximumSize(QSize(32, 32));
		chooseBufferDownAct = new QAction();
		bufferDownButton->setDefaultAction(chooseBufferDownAct);
		connect(chooseBufferDownAct, &QAction::triggered, this, &Window::chooseBufferDown);
		bufferDownIcon = new QIcon(":/graphics/graphics/bufferDown.png");
		bufferDownButton->setIcon(*bufferDownIcon);
		elementMenuLayout->addWidget(bufferDownButton, 2, 2);

		bufferUpButton = new QToolButton();
		bufferUpButton->setMaximumSize(QSize(32, 32));
		chooseBufferUpAct = new QAction();
		bufferUpButton->setDefaultAction(chooseBufferUpAct);
		connect(chooseBufferUpAct, &QAction::triggered, this, &Window::chooseBufferUp);
		bufferUpIcon = new QIcon(":/graphics/graphics/bufferUp.png");
		bufferUpButton->setIcon(*bufferUpIcon);
		elementMenuLayout->addWidget(bufferUpButton, 2, 3);

		bufferLeftUpButton = new QToolButton();
		bufferLeftUpButton->setMaximumSize(QSize(32, 32));
		chooseBufferLeftUpAct = new QAction();
		bufferLeftUpButton->setDefaultAction(chooseBufferLeftUpAct);
		connect(chooseBufferLeftUpAct, &QAction::triggered, this, &Window::chooseBufferLeftUp);
		bufferLeftUpIcon = new QIcon(":/graphics/graphics/bufferLeftUp.png");
		bufferLeftUpButton->setIcon(*bufferLeftUpIcon);
		elementMenuLayout->addWidget(bufferLeftUpButton, 2, 4);

		bufferRightUpButton = new QToolButton();
		bufferRightUpButton->setMaximumSize(QSize(32, 32));
		chooseBufferRightUpAct = new QAction();
		bufferRightUpButton->setDefaultAction(chooseBufferRightUpAct);
		connect(chooseBufferRightUpAct, &QAction::triggered, this, &Window::chooseBufferRightUp);
		bufferRightUpIcon = new QIcon(":/graphics/graphics/bufferRightUp.png");
		bufferRightUpButton->setIcon(*bufferRightUpIcon);
		elementMenuLayout->addWidget(bufferRightUpButton, 2, 5);

		bufferLeftDownButton = new QToolButton();
		bufferLeftDownButton->setMaximumSize(QSize(32, 32));
		chooseBufferLeftDownAct = new QAction();
		bufferLeftDownButton->setDefaultAction(chooseBufferLeftDownAct);
		connect(chooseBufferLeftDownAct, &QAction::triggered, this, &Window::chooseBufferLeftDown);
		bufferLeftDownIcon = new QIcon(":/graphics/graphics/bufferLeftDown.png");
		bufferLeftDownButton->setIcon(*bufferLeftDownIcon);
		elementMenuLayout->addWidget(bufferLeftDownButton, 2, 6);

		bufferRightDownButton = new QToolButton();
		bufferRightDownButton->setMaximumSize(QSize(32, 32));
		chooseBufferRightDownAct = new QAction();
		bufferRightDownButton->setDefaultAction(chooseBufferRightDownAct);
		connect(chooseBufferRightDownAct, &QAction::triggered, this, &Window::chooseBufferRightDown);
		bufferRightDownIcon = new QIcon(":/graphics/graphics/bufferRightDown.png");
		bufferRightDownButton->setIcon(*bufferRightDownIcon);
		elementMenuLayout->addWidget(bufferRightDownButton, 2, 7);

		signalLeftButton = new QToolButton();
		signalLeftButton->setMaximumSize(QSize(32, 32));
		chooseSignalLeftAct = new QAction();
		signalLeftButton->setDefaultAction(chooseSignalLeftAct);
		connect(chooseSignalLeftAct, &QAction::triggered, this, &Window::chooseSignalLeft);
		signalLeftIcon = new QIcon(":/graphics/graphics/signalLeft.png");
		shuntLeftIcon = new QIcon(":/graphics/graphics/shuntLeftRed.png");
		signalLeftButton->setIcon(*signalLeftIcon);
		elementMenuLayout->addWidget(signalLeftButton, 2, 8);

		signalRightButton = new QToolButton();
		signalRightButton->setMaximumSize(QSize(32, 32));
		chooseSignalRightAct = new QAction();
		signalRightButton->setDefaultAction(chooseSignalRightAct);
		connect(chooseSignalRightAct, &QAction::triggered, this, &Window::chooseSignalRight);
		signalRightIcon = new QIcon(":/graphics/graphics/signalRight.png");
		shuntRightIcon = new QIcon(":/graphics/graphics/shuntRightRed.png");
		signalRightButton->setIcon(*signalRightIcon);
		elementMenuLayout->addWidget(signalRightButton, 2, 9);

		signalDownButton = new QToolButton();
		signalDownButton->setMaximumSize(QSize(32, 32));
		chooseSignalDownAct = new QAction();
		signalDownButton->setDefaultAction(chooseSignalDownAct);
		connect(chooseSignalDownAct, &QAction::triggered, this, &Window::chooseSignalDown);
		signalDownIcon = new QIcon(":/graphics/graphics/signalDown.png");
		shuntDownIcon = new QIcon(":/graphics/graphics/shuntDownRed.png");
		signalDownButton->setIcon(*signalDownIcon);
		elementMenuLayout->addWidget(signalDownButton, 2, 10);

		signalUpButton = new QToolButton();
		signalUpButton->setMaximumSize(QSize(32, 32));
		chooseSignalUpAct = new QAction();
		signalUpButton->setDefaultAction(chooseSignalUpAct);
		connect(chooseSignalUpAct, &QAction::triggered, this, &Window::chooseSignalUp);
		signalUpIcon = new QIcon(":/graphics/graphics/signalUp.png");
		shuntUpIcon = new QIcon(":/graphics/graphics/shuntUpRed.png");
		signalUpButton->setIcon(*signalUpIcon);
		elementMenuLayout->addWidget(signalUpButton, 2, 11);

		signalLeftUpButton = new QToolButton();
		signalLeftUpButton->setMaximumSize(QSize(32, 32));
		chooseSignalLeftUpAct = new QAction();
		signalLeftUpButton->setDefaultAction(chooseSignalLeftUpAct);
		connect(chooseSignalLeftUpAct, &QAction::triggered, this, &Window::chooseSignalLeftUp);
		signalLeftUpIcon = new QIcon(":/graphics/graphics/signalLeftUp.png");
		shuntLeftUpIcon = new QIcon(":/graphics/graphics/shuntLeftUpRed.png");
		signalLeftUpButton->setIcon(*signalLeftUpIcon);
		elementMenuLayout->addWidget(signalLeftUpButton, 2, 12);

		signalRightUpButton = new QToolButton();
		signalRightUpButton->setMaximumSize(QSize(32, 32));
		chooseSignalRightUpAct = new QAction();
		signalRightUpButton->setDefaultAction(chooseSignalRightUpAct);
		connect(chooseSignalRightUpAct, &QAction::triggered, this, &Window::chooseSignalRightUp);
		signalRightUpIcon = new QIcon(":/graphics/graphics/signalRightUp.png");
		shuntRightUpIcon = new QIcon(":/graphics/graphics/shuntRightUpRed.png");
		signalRightUpButton->setIcon(*signalRightUpIcon);
		elementMenuLayout->addWidget(signalRightUpButton, 2, 13);

		signalLeftDownButton = new QToolButton();
		signalLeftDownButton->setMaximumSize(QSize(32, 32));
		chooseSignalLeftDownAct = new QAction();
		signalLeftDownButton->setDefaultAction(chooseSignalLeftDownAct);
		connect(chooseSignalLeftDownAct, &QAction::triggered, this, &Window::chooseSignalLeftDown);
		signalLeftDownIcon = new QIcon(":/graphics/graphics/signalLeftDown.png");
		shuntLeftDownIcon = new QIcon(":/graphics/graphics/shuntLeftDownRed.png");
		signalLeftDownButton->setIcon(*signalLeftDownIcon);
		elementMenuLayout->addWidget(signalLeftDownButton, 2, 14);

		signalRightDownButton = new QToolButton();
		signalRightDownButton->setMaximumSize(QSize(32, 32));
		chooseSignalRightDownAct = new QAction();
		signalRightDownButton->setDefaultAction(chooseSignalRightDownAct);
		connect(chooseSignalRightDownAct, &QAction::triggered, this, &Window::chooseSignalRightDown);
		signalRightDownIcon = new QIcon(":/graphics/graphics/signalRightDown.png");
		shuntRightDownIcon = new QIcon(":/graphics/graphics/shuntRightDownRed.png");
		signalRightDownButton->setIcon(*signalRightDownIcon);
		elementMenuLayout->addWidget(signalRightDownButton, 2, 15);

		bridge1Button = new QToolButton();
		bridge1Button->setMaximumSize(QSize(32, 32));
		chooseBridge1Act = new QAction();
		bridge1Button->setDefaultAction(chooseBridge1Act);
		connect(chooseBridge1Act, &QAction::triggered, this, &Window::chooseBridge1);
		bridge1Icon = new QIcon(":/graphics/graphics/bridgeSet1.png");
		bridge1Button->setIcon(*bridge1Icon);
		elementMenuLayout->addWidget(bridge1Button, 2, 16);

		bridge2Button = new QToolButton();
		bridge2Button->setMaximumSize(QSize(32, 32));
		chooseBridge2Act = new QAction();
		bridge2Button->setDefaultAction(chooseBridge2Act);
		connect(chooseBridge2Act, &QAction::triggered, this, &Window::chooseBridge2);
		bridge2Icon = new QIcon(":/graphics/graphics/bridgeSet2.png");
		bridge2Button->setIcon(*bridge2Icon);
		elementMenuLayout->addWidget(bridge2Button, 2, 17);

		underpass1Button = new QToolButton();
		underpass1Button->setMaximumSize(QSize(32, 32));
		chooseUnderpass1Act = new QAction();
		underpass1Button->setDefaultAction(chooseUnderpass1Act);
		connect(chooseUnderpass1Act, &QAction::triggered, this, &Window::chooseUnderpass1);
		underpass1Icon = new QIcon(":/graphics/graphics/underpassSet1.png");
		underpass1Button->setIcon(*underpass1Icon);
		elementMenuLayout->addWidget(underpass1Button, 2, 18);

		underpass2Button = new QToolButton();
		underpass2Button->setMaximumSize(QSize(32, 32));
		chooseUnderpass2Act = new QAction();
		underpass2Button->setDefaultAction(chooseUnderpass2Act);
		connect(chooseUnderpass2Act, &QAction::triggered, this, &Window::chooseUnderpass2);
		underpass2Icon = new QIcon(":/graphics/graphics/underpassSet2.png");
		underpass2Button->setIcon(*underpass2Icon);
		elementMenuLayout->addWidget(underpass2Button, 2, 19);

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

#include "map.h"

//private

void Map::showElementAlreadyThereError()
{
	//Show error if an element already exists there.
	QMessageBox elementExistsAlreadyAlert;
	elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
	elementExistsAlreadyAlert.setText("An element already exists here.");
	elementExistsAlreadyAlert.exec();
}

void Map::addStraightTrack(std::shared_ptr<StraightTrack> newStraightTrack)
{
	int tempLocationX = newStraightTrack->getLocationX();
	int templocationY = newStraightTrack->getLocationY();
	if (!checkElementExists(tempLocationX, templocationY))
	{
		straightTrackList.push_back(newStraightTrack);
		++totalTrack;
	}
	else
	{
		showElementAlreadyThereError();
	}
}

void Map::addDirectedTrack(std::shared_ptr<DirectedTrack> newDirectedTrack)
{
	int tempLocationX = newDirectedTrack->getLocationX();
		int templocationY = newDirectedTrack->getLocationY();
		if (!checkElementExists(tempLocationX, templocationY))
		{
			directedTrackList.push_back(newDirectedTrack);
			++totalTrack;
		}
		else
		{
			showElementAlreadyThereError();
		}
}

void Map::addCurvedTrack(std::shared_ptr<CurvedTrack> newCurvedTrack)
{
	int tempLocationX = newCurvedTrack->getLocationX();
	int templocationY = newCurvedTrack->getLocationY();
	if (!checkElementExists(tempLocationX, templocationY))
	{
		curvedTrackList.push_back(newCurvedTrack);
		++totalTrack;
	}
	else
	{
		showElementAlreadyThereError();
	}
}

void Map::addLinkedTrack(std::shared_ptr<LinkedTrack> newLinkedTrack)
{
	int tempLocationX = newLinkedTrack->getLocationX();
	int templocationY = newLinkedTrack->getLocationY();
	if (!checkElementExists(tempLocationX, templocationY))
	{
		linkedTrackList.push_back(newLinkedTrack);
		++totalTrack;
	}
	else
	{
		showElementAlreadyThereError();
	}
}

void Map::addExitTrack(std::shared_ptr<ExitTrack> newExitTrack)
{
	int tempLocationX = newExitTrack->getLocationX();
	int templocationY = newExitTrack->getLocationY();
	if (!checkElementExists(tempLocationX, templocationY))
	{
		exitTrackList.push_back(newExitTrack);
	}
	else
	{
		showElementAlreadyThereError();
	}
}

void Map::addBufferTrack(std::shared_ptr<BufferTrack> newBufferTrack)
{
	int tempLocationX = newBufferTrack->getLocationX();
	int templocationY = newBufferTrack->getLocationY();
	if (!checkElementExists(tempLocationX, templocationY))
	{
		bufferTrackList.push_back(newBufferTrack);
		++totalTrack;
	}
	else
	{
		showElementAlreadyThereError();
	}
}

void Map::addSignalTrack(std::shared_ptr<SignalTrack> newSignalTrack)
{
	int tempLocationX = newSignalTrack->getLocationX();
	int templocationY = newSignalTrack->getLocationY();
	if (!checkElementExists(tempLocationX, templocationY))
	{
		signalTrackList.push_back(newSignalTrack);
		++totalTrack;
	}
	else
	{
		showElementAlreadyThereError();
	}
}

void Map::addBridgeUnderpassTrack(std::shared_ptr<BridgeUnderpassTrack> newBridgeUnderpassTrack)
{
	int tempLocationX = newBridgeUnderpassTrack->getLocationX();
	int templocationY = newBridgeUnderpassTrack->getLocationY();
	if (!checkElementExists(tempLocationX, templocationY))
	{
		bridgeUnderpassTrackList.push_back(newBridgeUnderpassTrack);
		++totalTrack;
	}
	else
	{
		showElementAlreadyThereError();
	}
}

//public

Map::Map()
{

}

int Map::getTotalTrack() const
{
	return totalTrack;
}

void Map::setTotalTrack(int newTrackTotal)
{
	totalTrack = newTrackTotal;
}

bool Map::checkElementExists(int locationX, int locationY)
{
	bool found = false;
	if (!straightTrackList.empty())
	{
		for (std::shared_ptr<StraightTrack>& currentElement : straightTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!directedTrackList.empty() && found == false)
	{
		for (std::shared_ptr<DirectedTrack>& currentElement : directedTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!curvedTrackList.empty() && found == false)
	{
		for (std::shared_ptr<CurvedTrack>& currentElement : curvedTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!linkedTrackList.empty() && found == false)
	{
		for (std::shared_ptr<LinkedTrack>& currentElement : linkedTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!exitTrackList.empty() && found == false)
	{
		for (std::shared_ptr<ExitTrack>& currentElement : exitTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!bufferTrackList.empty() && found == false)
	{
		for (std::shared_ptr<BufferTrack>& currentElement : bufferTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!signalTrackList.empty() && found == false)
	{
		for (std::shared_ptr<SignalTrack>& currentElement : signalTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!bridgeUnderpassTrackList.empty() && found == false)
	{
		for (std::shared_ptr<BridgeUnderpassTrack>& currentElement : bridgeUnderpassTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!switchTrackList.empty() && found == false)
	{
		for (std::shared_ptr<SwitchTrack>& currentElement : switchTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}
	if (!crossoverTrackList.empty() && found == false)
	{
		for (std::shared_ptr<CrossoverTrack>& currentElement : crossoverTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!flyoverTrackList.empty() && found == false)
	{
		for (std::shared_ptr<FlyoverTrack>& currentElement : flyoverTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!namedLocationList.empty() && found == false)
	{
		for (std::shared_ptr<NamedLocation>& currentElement : namedLocationList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!concourseList.empty() && found == false)
	{
		for (std::shared_ptr<Concourse>& currentElement : concourseList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}
	if (!parapetList.empty() && found == false)
	{
		for (std::shared_ptr<Parapet>& currentElement : parapetList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}
	return found;
}

bool Map::checkTextExists(int locationX, int locationY)
{
	bool found = false;
	if (!textList.empty())
	{
		for (std::shared_ptr<Text>& currentText : textList)
		{
			int textCurrentX = currentText->getLocationX();
			int textCurrentY = currentText->getLocationY();
			int textEditableX = currentText->getEditableX();
			int textEditableY = currentText->getEditableY();
			if (locationX >= textCurrentX && locationX <=textEditableX)
			{
				if (locationY >= textCurrentY && locationY <= textEditableY)
				{
				found = true;
				}
			}
		}
	}
	return found;
}



//StraightTrack related methods

std::vector<std::shared_ptr<StraightTrack> > Map::getStraightTrackList() const
{
	return straightTrackList;
}

void Map::setStraightTrackList(const std::vector<std::shared_ptr<StraightTrack> >& newSignalTrackList)
{
	straightTrackList = newSignalTrackList;
}

void Map::createAddStraightTrack(StraightType straightType, int overallX, int overallY)
{
	std::shared_ptr<StraightTrack> straightTrack(new StraightTrack(straightType, overallX, overallY));
	addStraightTrack(straightTrack);
}

std::shared_ptr<StraightTrack> Map::getStraightTrackAt(int locationX, int locationY)
{
	std::shared_ptr<StraightTrack> straightTrack = nullptr;
	if (!straightTrackList.empty())
	{
		//Loop through all the straight tracks to see if one exists at these coordiantes.
		for (std::shared_ptr<StraightTrack>& currentElement : straightTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				straightTrack = currentElement;
				break;
			}
		}
	}
	return straightTrack;
}

//DirectedTrack related methods

std::vector<std::shared_ptr<DirectedTrack> > Map::getDirectedTrackList() const
{
	return directedTrackList;
}

void Map::setDirectedTrackList(const std::vector<std::shared_ptr<DirectedTrack> >& newDirectedTrackList)
{
	directedTrackList = newDirectedTrackList;
}

void Map::createAddDirectedTrack(DirectedType directedType, int overallX, int overallY)
{
	std::shared_ptr<DirectedTrack> directedTrack(new DirectedTrack(directedType, overallX, overallY));
	addDirectedTrack(directedTrack);
}

std::shared_ptr<DirectedTrack> Map::getDirectedTrackAt(int locationX, int locationY)
{
	std::shared_ptr<DirectedTrack> directedTrack = nullptr;
	if (!directedTrackList.empty())
	{
		for (std::shared_ptr<DirectedTrack>& currentElement : directedTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				directedTrack = currentElement;
				break;
			}
		}
	}
	return directedTrack;
}

//CurvedTrack related methods

std::vector<std::shared_ptr<CurvedTrack> > Map::getCurvedTrackList() const
{
	return curvedTrackList;
}

void Map::setCurvedTrackList(const std::vector<std::shared_ptr<CurvedTrack> >& newCurvedTrackList)
{
	curvedTrackList = newCurvedTrackList;
}

void Map::createAddCurvedTrack(CurvedType curvedType, int overallX, int overallY)
{
	std::shared_ptr<CurvedTrack> curvedTrack(new CurvedTrack(curvedType, overallX, overallY));
	addCurvedTrack(curvedTrack);
}

std::shared_ptr<CurvedTrack> Map::getCurvedTrackAt(int locationX, int locationY)
{
	std::shared_ptr<CurvedTrack> curvedTrack = nullptr;
	if (!curvedTrackList.empty())
	{
		for (std::shared_ptr<CurvedTrack>& currentElement : curvedTrackList)
		{

			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				curvedTrack = currentElement;
				break;
			}
		}
	}
	return curvedTrack;
}

//LinkedTrack related methods

std::vector<std::shared_ptr<LinkedTrack> > Map::getLinkedTrackList() const
{
	return linkedTrackList;
}

void Map::setLinkedTrackList(const std::vector<std::shared_ptr<LinkedTrack> >& newLinkedTrackList)
{
	linkedTrackList = newLinkedTrackList;
}

void Map::createAddLinkedTrack(LinkedType linkedType, int overallX, int overallY)
{
	std::shared_ptr<LinkedTrack> linkedTrack(new LinkedTrack(linkedType, overallX, overallY));
	addLinkedTrack(linkedTrack);
}

std::shared_ptr<LinkedTrack> Map::getLinkedTrackAt(int locationX, int locationY)
{
	std::shared_ptr<LinkedTrack> linkedTrack = nullptr;
	if (!linkedTrackList.empty())
	{
		for (std::shared_ptr<LinkedTrack>& currentElement : linkedTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				linkedTrack = currentElement;
				break;
			}
		}
	}
	return linkedTrack;
}

//ExitTrack related methods

std::vector<std::shared_ptr<ExitTrack> > Map::getExitTrackList() const
{
	return exitTrackList;
}

void Map::setExitTrackList(const std::vector<std::shared_ptr<ExitTrack> >& newExitTrackList)
{
	exitTrackList = newExitTrackList;
}

void Map::createAddExitTrack(ExitType exitType, int overallX, int overallY)
{
	std::shared_ptr<ExitTrack> exitTrack(new ExitTrack(exitType, overallX, overallY));
	addExitTrack(exitTrack);
}

std::shared_ptr<ExitTrack> Map::getExitTrackAt(int locationX, int locationY)
{
	std::shared_ptr<ExitTrack> exitTrack = nullptr;
	if (!exitTrackList.empty())
	{
		for (std::shared_ptr<ExitTrack>& currentElement : exitTrackList)
		{

			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				exitTrack = currentElement;
				break;
			}
		}
	}
	return exitTrack;
}

//BufferTrack related methods

std::vector<std::shared_ptr<BufferTrack> > Map::getBufferTrackList() const
{
	return bufferTrackList;
}

void Map::setBufferTrackList(const std::vector<std::shared_ptr<BufferTrack> >& newBufferTrackList)
{
	bufferTrackList = newBufferTrackList;
}

void Map::createAddBufferTrack(BufferType bufferType, int overallX, int overallY)
{
	std::shared_ptr<BufferTrack> bufferTrack(new BufferTrack(bufferType, overallX, overallY));
	addBufferTrack(bufferTrack);
}

std::shared_ptr<BufferTrack> Map::getBufferTrackAt(int locationX, int locationY)
{
	std::shared_ptr<BufferTrack> bufferTrack = nullptr;
	if (!bufferTrackList.empty())
	{
		for (std::shared_ptr<BufferTrack>& currentElement : bufferTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				bufferTrack = currentElement;
				break;
			}
		}
	}
	return bufferTrack;
}

//SignalTrack related methods

std::vector<std::shared_ptr<SignalTrack> > Map::getSignalTrackList() const
{
	return signalTrackList;
}

void Map::setSignalTrackList(const std::vector<std::shared_ptr<SignalTrack> >& newSignalTrackList)
{
	signalTrackList = newSignalTrackList;
}

void Map::createAddSignalTrack(SignalType signalType, int aspect, int overallX, int overallY)
{
	std::shared_ptr<SignalTrack> signalTrack(new SignalTrack(signalType, aspect, overallX, overallY));
	addSignalTrack(signalTrack);
}

std::shared_ptr<SignalTrack> Map::getSignalTrackAt(int locationX, int locationY)
{
	std::shared_ptr<SignalTrack> signalTrack = nullptr;
	if (!signalTrackList.empty())
	{
		for (std::shared_ptr<SignalTrack>& currentElement : signalTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				signalTrack = currentElement;
				break;
			}
		}
	}
	return signalTrack;
}

//BridgeUnderpassTrack related methods

std::vector<std::shared_ptr<BridgeUnderpassTrack> > Map::getBridgeUnderpassTrackList() const
{
	return bridgeUnderpassTrackList;
}

void Map::setBridgeUnderpassTrackList(const std::vector<std::shared_ptr<BridgeUnderpassTrack> >& newBridgeUnderpassTrackList)
{
	bridgeUnderpassTrackList = newBridgeUnderpassTrackList;
}

void Map::createAddBridgeUnderpassTrack(BridgeUnderpassType bridgeUnderpassType, int overallX, int overallY)
{
	std::shared_ptr<BridgeUnderpassTrack> bridgeUnderpassTrack(new BridgeUnderpassTrack(bridgeUnderpassType, overallX, overallY));
	addBridgeUnderpassTrack(bridgeUnderpassTrack);
}

std::shared_ptr<BridgeUnderpassTrack> Map::getBridgeUnderpassTrack(int locationX, int locationY)
{
	std::shared_ptr<BridgeUnderpassTrack> bridgeUnderpassTrack = nullptr;
	if (!bridgeUnderpassTrackList.empty())
	{
		for (std::shared_ptr<BridgeUnderpassTrack>& currentElement : bridgeUnderpassTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				bridgeUnderpassTrack = currentElement;
				break;
			}
		}
	}
	return bridgeUnderpassTrack;
}

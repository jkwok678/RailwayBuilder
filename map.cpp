#include "map.h"

//private

//General methods.




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
		Message::showElementAlreadyThereErrorMessage();
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
		Message::showElementAlreadyThereErrorMessage();
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
		Message::showElementAlreadyThereErrorMessage();
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
		Message::showElementAlreadyThereErrorMessage();
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
		Message::showElementAlreadyThereErrorMessage();
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
		Message::showElementAlreadyThereErrorMessage();
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
		Message::showElementAlreadyThereErrorMessage();
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
		Message::showElementAlreadyThereErrorMessage();
	}
}

void Map::addSwitchTrack(std::shared_ptr<SwitchTrack> newSwitchTrack)
{
	int tempLocationX = newSwitchTrack->getLocationX();
	int templocationY = newSwitchTrack->getLocationY();
	if (!checkElementExists(tempLocationX, templocationY))
	{
		switchTrackList.push_back(newSwitchTrack);
		++totalTrack;
	}
	else
	{
		Message::showElementAlreadyThereErrorMessage();
	}
}

void Map::addCrossoverTrack(std::shared_ptr<CrossoverTrack> newCrossoverTrack)
{
	int tempLocationX = newCrossoverTrack->getLocationX();
	int templocationY = newCrossoverTrack->getLocationY();
	if (!checkElementExists(tempLocationX, templocationY))
	{
		crossoverTrackList.push_back(newCrossoverTrack);
		++totalTrack;
	}
	else
	{
		Message::showElementAlreadyThereErrorMessage();
	}
}

void Map::addFlyoverTrack(std::shared_ptr<FlyoverTrack> newFlyoverTrack)
{
	int tempLocationX = newFlyoverTrack->getLocationX();
	int templocationY = newFlyoverTrack->getLocationY();
	if (!checkElementExists(tempLocationX, templocationY))
	{
		flyoverTrackList.push_back(newFlyoverTrack);
		++totalTrack;
	}
	else
	{
		Message::showElementAlreadyThereErrorMessage();
	}
}

void Map::addNamedLocation(std::shared_ptr<NamedLocation> newNamedLocation)
{
	int tempLocationX = newNamedLocation->getLocationX();
	int templocationY = newNamedLocation->getLocationY();
	if (!checkElementExists(tempLocationX, templocationY))
	{
		namedLocationList.push_back(newNamedLocation);
	}
	else
	{
		Message::showElementAlreadyThereErrorMessage();
	}
}

void Map::addConcourse(std::shared_ptr<Concourse> newConcourseTrack)
{
	int tempLocationX = newConcourseTrack->getLocationX();
	int templocationY = newConcourseTrack->getLocationY();
	if (!checkElementExists(tempLocationX, templocationY))
	{
		concourseList.push_back(newConcourseTrack);
	}
	else
	{
		Message::showElementAlreadyThereErrorMessage();
	}
}

void Map::addParapet(std::shared_ptr<Parapet> newParapet)
{

	int tempLocationX = newParapet->getLocationX();
	int templocationY = newParapet->getLocationY();
	if (!checkElementExists(tempLocationX, templocationY))
	{
		parapetList.push_back(newParapet);
	}
	else
	{
		Message::showElementAlreadyThereErrorMessage();
	}

}

void Map::addText(std::shared_ptr<Text> newText)
{
	int tempLocationX = newText->getLocationX();
	int templocationY = newText->getLocationY();
	textList.push_back(newText);

}

//Remove element methods

bool Map::removeStraightTrack(int xLocation, int yLocation)
{
	for (unsigned int i = 0; i < straightTrackList.size(); i++)
	{
		std::shared_ptr<StraightTrack>& currentElement = straightTrackList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == xLocation && currentY == yLocation)
		{
			straightTrackList.erase(straightTrackList.begin() + i);
			return true;
		}
	}
	return false;
}

bool Map::removeDirectedTrack(int xLocation, int yLocation)
{
	for (unsigned int i = 0; i < directedTrackList.size(); i++)
	{
		std::shared_ptr<DirectedTrack>& currentElement = directedTrackList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == xLocation && currentY == yLocation)
		{
			directedTrackList.erase(directedTrackList.begin() + i);
			return true;
		}
	}
	return false;
}

bool Map::removeCurvedTrack(int xLocation, int yLocation)
{
	for (unsigned int i = 0; i < curvedTrackList.size(); i++)
	{
		std::shared_ptr<CurvedTrack>& currentElement = curvedTrackList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == xLocation && currentY == yLocation)
		{
			curvedTrackList.erase(curvedTrackList.begin() + i);
			return true;
		}
	}
	return false;
}

bool Map::removeLinkedTrack(int xLocation, int yLocation)
{
	for (unsigned int i = 0; i < linkedTrackList.size(); i++)
	{
		std::shared_ptr<LinkedTrack>& currentElement = linkedTrackList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == xLocation && currentY == yLocation)
		{
			if (currentElement->getLinked())
			{
				disconnectLinkedTrack(currentElement,currentElement->getOtherLinkedTrack());
			}
			linkedTrackList.erase(linkedTrackList.begin() + i);
			return true;
		}
	}
	return false;
}

bool Map::removeExitTrack(int xLocation, int yLocation)
{
	for (int i = 0; i < exitTrackList.size(); i++)
	{
		std::shared_ptr<ExitTrack>& currentElement = exitTrackList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == xLocation && currentY == yLocation)
		{
			exitTrackList.erase(exitTrackList.begin() + i);
			return true;
		}
	}
	return false;
}

bool Map::removeBufferTrack(int xLocation, int yLocation)
{
	for (unsigned int i = 0; i < bufferTrackList.size(); i++)
	{
		std::shared_ptr<BufferTrack>& currentElement = bufferTrackList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == xLocation && currentY == yLocation)
		{
			bufferTrackList.erase(bufferTrackList.begin() + i);
			return true;
		}
	}
	return false;
}

bool Map::removeSignalTrack(int xLocation, int yLocation)
{

	for (unsigned int i = 0; i < signalTrackList.size(); i++)
	{
		std::shared_ptr<SignalTrack>& currentElement = signalTrackList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == xLocation && currentY == yLocation)
		{
			signalTrackList.erase(signalTrackList.begin() + i);
			return true;
		}
	}
	return false;
}

bool Map::removeBridgeUnderpassTrack(int xLocation, int yLocation)
{
	for (unsigned int i = 0; i < bridgeUnderpassTrackList.size(); i++)
	{
		std::shared_ptr<BridgeUnderpassTrack>& currentElement = bridgeUnderpassTrackList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == xLocation && currentY == yLocation)
		{
			bridgeUnderpassTrackList.erase(bridgeUnderpassTrackList.begin() + i);
			return true;
		}
	}
	return false;
}

bool Map::removeSwitchTrack(int xLocation, int yLocation)
{
	for (unsigned int i = 0; i < switchTrackList.size(); i++)
	{
		std::shared_ptr<SwitchTrack>& currentElement = switchTrackList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == xLocation && currentY == yLocation)
		{
			switchTrackList.erase(switchTrackList.begin() + i);
			return true;
		}
	}
	return false;
}

bool Map::removeCrossoverTrack(int xLocation, int yLocation)
{
	for (unsigned int i = 0; i < crossoverTrackList.size(); i++)
	{
		std::shared_ptr<CrossoverTrack>& currentElement = crossoverTrackList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == xLocation && currentY == yLocation)
		{
			crossoverTrackList.erase(crossoverTrackList.begin() + i);
			return true;
		}
	}
	return false;
}

bool Map::removeFlyoverTrack(int xLocation, int yLocation)
{
	for (unsigned int i = 0; i < flyoverTrackList.size(); i++)
	{
		std::shared_ptr<FlyoverTrack>& currentElement = flyoverTrackList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == xLocation && currentY == yLocation)
		{
			flyoverTrackList.erase(flyoverTrackList.begin() + i);
			return true;
		}
	}
	return false;
}

bool Map::removeNamedLocation(int xLocation, int yLocation)
{
	for (unsigned int i = 0; i < namedLocationList.size(); i++)
	{
		std::shared_ptr<NamedLocation>& currentElement = namedLocationList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == xLocation && currentY == yLocation)
		{
			namedLocationList.erase(namedLocationList.begin() + i);
			return true;
		}
	}
	return false;
}

bool Map::removeConcourse(int xLocation, int yLocation)
{
	for (unsigned int i = 0; i < concourseList.size(); i++)
	{
		std::shared_ptr<Concourse>& currentElement = concourseList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == xLocation && currentY == yLocation)
		{
			concourseList.erase(concourseList.begin() + i);
			return true;
		}
	}
	return false;
}

bool Map::removeParapet(int xLocation, int yLocation)
{
	for (unsigned int i = 0; i < parapetList.size(); i++)
	{
		std::shared_ptr<Parapet>& currentElement = parapetList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == xLocation && currentY == yLocation)
		{
			parapetList.erase(parapetList.begin() + i);
			return true;
		}
	}
	return false;
}

//Linked Track private methods

void Map::connectLinkedTrack()
{
	linkedTrack1->setOtherLinkedTrack(linkedTrack2);
	linkedTrack2->setOtherLinkedTrack(linkedTrack1);
	linkedTrack1->setLinked(true);
	linkedTrack2->setLinked(true);
	resetConnectLinkedTrack();
}

void Map::disconnectLinkedTrack(std::shared_ptr<LinkedTrack> alreadyLinkedTrack1, std::shared_ptr<LinkedTrack> alreadyLinkedTrack2)
{
	alreadyLinkedTrack1->removeOtherLinkedTrack();
	alreadyLinkedTrack1->setLinked(false);
	alreadyLinkedTrack2->removeOtherLinkedTrack();
	alreadyLinkedTrack2->setLinked(false);
}

void Map::resetConnectLinkedTrack()
{
	linkedTrack1 = nullptr;
	linkedTrack2 = nullptr;
}

//General methods

std::shared_ptr<Track> Map::findTopLeftTrack()
{
	std::shared_ptr<Track> track = nullptr;
	makeTrackList();
	std::vector<std::shared_ptr<Track>> tempTrackList = trackList;
	if (!tempTrackList.empty())
	{
		track = tempTrackList[0];
		for (std::shared_ptr<Track> currentTrack: tempTrackList)
		{
			if (currentTrack->getLocationX() < track->getLocationX())
			{
				if (currentTrack->getLocationY() > track->getLocationY())
				{
					track = currentTrack;
				}
			}
		}
	}
	return track;
}





//public

Map::Map()
{

}

int Map::getImageSize() const
{
	return imageSize;
}

void Map::setImageSize(int newImageSize)
{
	imageSize = newImageSize;
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

QString Map::straightTrackListToQStringForSaving()
{
	QString straightTrackQStringList;
	for (std::shared_ptr<StraightTrack> straightTrack: straightTrackList) {

	}
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

	//Connecting Linked tracks methods

std::shared_ptr<LinkedTrack> Map::getLinkedTrack1() const
{
	return linkedTrack1;
}

void Map::setLinkedTrack1(const std::shared_ptr<LinkedTrack> &newLinkedTrack1)
{
	linkedTrack1 = newLinkedTrack1;
}

std::shared_ptr<LinkedTrack> Map::getLinkedTrack2() const
{
	return linkedTrack2;
}

void Map::setLinkedTrack2(const std::shared_ptr<LinkedTrack> &newLinkedTrack2)
{
	linkedTrack2 = newLinkedTrack2;
}

bool Map::hasLinkedTrackAt(int locationX, int locationY)
{
	if (getLinkedTrackAt(locationX,locationY) == nullptr)
	{
		return false;
	}
	return true;
}

void Map::connectTwoLinkedTracks(int locationX, int locationY)
{
	if (linkedTrack1 == nullptr)
	{
		if (hasLinkedTrackAt(locationX,locationY))
		{
			std::shared_ptr<LinkedTrack> temp1 = getLinkedTrackAt(locationX, locationY);
			linkedTrack1 = temp1;
		}
	}
	else if (linkedTrack2 == nullptr && linkedTrack1 != nullptr)
	{
		if (hasLinkedTrackAt(locationX,locationY))
		{
			std::shared_ptr<LinkedTrack> temp2 = getLinkedTrackAt(locationX, locationY);
			if (temp2 != linkedTrack1)
			{
				linkedTrack2 = temp2;
				if (!temp2->getLinked())
				{

					connectLinkedTrack();
				}
				else
				{
					if (linkedTrack1->getLinked())
					{
						disconnectLinkedTrack(linkedTrack1,linkedTrack1->getOtherLinkedTrack());
					}
					if (linkedTrack2->getLinked())
					{
						disconnectLinkedTrack(linkedTrack2,linkedTrack2->getOtherLinkedTrack());
					}
					connectLinkedTrack();
				}
			}
		}
	}
}

bool Map::checkAllLinkTrackLinked()
{
	bool allLinkedTrackLinked = true;
	if (linkedTrackList.size() % 2 ==0)
	{
		for (std::shared_ptr<LinkedTrack> linkedTrack: linkedTrackList)
		{
			if (!linkedTrack->getLinked())
			{
				allLinkedTrackLinked = false;
				break;
			}
		}
	}
	return allLinkedTrackLinked;
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


//SwitchTrack related methods

std::vector<std::shared_ptr<SwitchTrack> > Map::getSwitchTrackList() const
{
	return switchTrackList;
}

void Map::setSwitchTrackList(const std::vector<std::shared_ptr<SwitchTrack> >& newSwitchTrackList)
{
	switchTrackList = newSwitchTrackList;
}

void Map::createAddSwitchTrack(SwitchType switchType, int overallX, int overallY)
{
	std::shared_ptr<SwitchTrack> switchTrack(new SwitchTrack(switchType, overallX, overallY));
	addSwitchTrack(switchTrack);
}

std::shared_ptr<SwitchTrack> Map::getSwitchTrackAt(int locationX, int locationY)
{
	std::shared_ptr<SwitchTrack> switchTrack = nullptr;
	if (!switchTrackList.empty())
	{
		for (std::shared_ptr<SwitchTrack>& currentElement : switchTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				switchTrack = currentElement;
				break;
			}
		}
	}
	return switchTrack;
}


//CrossoverTrack related methods

std::vector<std::shared_ptr<CrossoverTrack> > Map::getCrossoverTrackList() const
{
	return crossoverTrackList;
}

void Map::setCrossoverTrackList(const std::vector<std::shared_ptr<CrossoverTrack> >& newCrossoverTrackList)
{
	crossoverTrackList = newCrossoverTrackList;
}

void Map::createAddCrossoverTrack(CrossoverType crossoverType, int overallX, int overallY)
{
	std::shared_ptr<CrossoverTrack> crossoverTrack(new CrossoverTrack(crossoverType, overallX, overallY));
	addCrossoverTrack(crossoverTrack);
}

std::shared_ptr<CrossoverTrack> Map::getCrossoverTrackAt(int locationX, int locationY)
{
	bool found = false;
	std::shared_ptr<CrossoverTrack> crossoverTrack = nullptr;
	if (!crossoverTrackList.empty())
	{
		for (std::shared_ptr<CrossoverTrack>& currentElement : crossoverTrackList)
		{

			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				crossoverTrack = currentElement;
				found = true;
				break;
			}
		}
	}
	return crossoverTrack;
}


//FlyoverTrack related methods

std::vector<std::shared_ptr<FlyoverTrack> > Map::getFlyoverTrackList() const
{
	return flyoverTrackList;
}

void Map::setFlyoverTrackList(const std::vector<std::shared_ptr<FlyoverTrack> >& newFlyoverTrackList)
{
	flyoverTrackList = newFlyoverTrackList;
}

void Map::createAddFlyoverTrack(FlyoverType flyoverType, int overallX, int overallY)
{
	std::shared_ptr<FlyoverTrack> flyoverTrack(new FlyoverTrack(flyoverType, overallX, overallY));
	addFlyoverTrack(flyoverTrack);
}

std::shared_ptr<FlyoverTrack> Map::getFlyoverTrackAt(int locationX, int locationY)
{
	bool found = false;
	std::shared_ptr<FlyoverTrack> flyoverTrack = nullptr;
	if (!flyoverTrackList.empty())
	{
		for (std::shared_ptr<FlyoverTrack>& currentElement : flyoverTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				flyoverTrack = currentElement;
				found = true;
				break;
			}
		}
	}
	return flyoverTrack;
}


//NamedLocation related methods

std::vector<std::shared_ptr<NamedLocation> > Map::getNamedLocationList() const
{
	return namedLocationList;
}

void Map::setNamedLocationList(const std::vector<std::shared_ptr<NamedLocation> >& newNamedLocationList)
{
	namedLocationList = newNamedLocationList;
}

void Map::createAddNamedLocation(int overallX, int overallY)
{
	std::shared_ptr<NamedLocation> namedLocation(new NamedLocation(overallX, overallY));
	addNamedLocation(namedLocation);
}

std::shared_ptr<NamedLocation> Map::getNamedLocationAt(int locationX, int locationY)
{
	std::shared_ptr<NamedLocation> namedLocation = nullptr;
	if (!namedLocationList.empty())
	{
		for (std::shared_ptr<NamedLocation>& currentElement : namedLocationList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				namedLocation = currentElement;
				break;
			}
		}
	}
	return namedLocation;
}


//Concourse related methods

std::vector<std::shared_ptr<Concourse> > Map::getConcourseList() const
{
	return concourseList;
}

void Map::setConcourseList(const std::vector<std::shared_ptr<Concourse> >& newConcourseList)
{
	concourseList = newConcourseList;
}

void Map::createAddConcourse(int overallX, int overallY)
{
	std::shared_ptr<Concourse> concourse(new Concourse(overallX, overallY));
	addConcourse(concourse);
}

std::shared_ptr<Concourse> Map::getConcourseAt(int locationX, int locationY)
{
	std::shared_ptr<Concourse> concourse = nullptr;
	if (!concourseList.empty())
	{
		for (std::shared_ptr<Concourse>& currentElement : concourseList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				concourse = currentElement;
				break;
			}
		}
	}
	return concourse;
}


//Parapet related methods

std::vector<std::shared_ptr<Parapet> > Map::getParapetList() const
{
	return parapetList;
}

void Map::setParapetList(const std::vector<std::shared_ptr<Parapet> >& newParapetList)
{
	parapetList = newParapetList;
}

void Map::createAddParapet(ParapetType parapetType, int overallX, int overallY)
{
	std::shared_ptr<Parapet> parapet(new Parapet(parapetType, overallX, overallY));
	addParapet(parapet);
}

std::shared_ptr<Parapet> Map::getParapetAt(int locationX, int locationY)
{
	bool found = false;
	std::shared_ptr<Parapet> parapet = nullptr;
	if (!parapetList.empty())
	{
		for (std::shared_ptr<Parapet>& currentElement : parapetList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				parapet = currentElement;
				found = true;
				break;
			}
		}
	}
	return parapet;
}

//Text related methods

std::vector<std::shared_ptr<Text> > Map::getTextList() const
{
	return textList;
}

void Map::setTextList(const std::vector<std::shared_ptr<Text> > &newTextList)
{
	textList = newTextList;
}

std::shared_ptr<Text> Map::createAddText(int overallX, int overallY, QString readableBit, QFont currentFont)
{
	std::shared_ptr<Text> text(new Text(overallX, overallY, readableBit, currentFont));
	addText(text);
	return text;
}

void Map::createAddLinkText(int overallX, int overallY, QString readableBit, bool ok, QFont currentFont)
{
	if (readableBit.startsWith(" "))
	{
		readableBit.clear();
	}
	if(!readableBit.isEmpty() && ok)
	{
		std::shared_ptr<Text> text = createAddText(overallX, overallY,readableBit,currentFont);
		linkLocalText(overallX, overallY, text);
	}
}

std::shared_ptr<Text> Map::getTextAt(int locationX, int locationY)
{
	std::shared_ptr<Text> text = nullptr;
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
				//Text point is at bottom left hand corner
				if (locationY >= textCurrentY && locationY <= textEditableY)
				{
					text = currentText;
				}
			}
		}
	}
	return text;
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

bool Map::deleteText(std::shared_ptr<Text> textToDelete)
{
	bool deleted = false;
	for (int i = 0; i < textList.size(); i++)
	{
		std::shared_ptr<Text>& currentText = textList[i];
		if (currentText == textToDelete)
		{
			textList.erase(textList.begin() + i);
			deleted = true;
			break;
		}
	}
	return deleted;
}

void Map::deleteTextFromAllElements(std::shared_ptr<Text> textToDelete)
{
	std::shared_ptr<Text> empty = nullptr;
	for (std::shared_ptr<StraightTrack> currentElement : straightTrackList)
	{
		if (currentElement->getText() == textToDelete)
		{
			currentElement->setText(empty);
			currentElement->setNamed(false);
		}
	}

	for (std::shared_ptr<DirectedTrack> currentElement : directedTrackList)
	{
		if (currentElement->getText() == textToDelete)
		{
			currentElement->setText(empty);
			currentElement->setNamed(false);
		}
	}

	for (std::shared_ptr<CurvedTrack> currentElement : curvedTrackList)
	{
		if (currentElement->getText() == textToDelete)
		{
			currentElement->setText(empty);
			currentElement->setNamed(false);
		}
	}

	for (std::shared_ptr<LinkedTrack> currentElement : linkedTrackList)
	{
		if (currentElement->getText() == textToDelete)
		{
			currentElement->setText(empty);
			currentElement->setNamed(false);
		}
	}

	for (std::shared_ptr<ExitTrack> currentElement : exitTrackList)
	{
		if (currentElement->getText() == textToDelete)
		{
			currentElement->setText(empty);
			currentElement->setNamed(false);
		}
	}
	for (std::shared_ptr<BufferTrack> currentElement : bufferTrackList)
	{
		if (currentElement->getText() == textToDelete)
		{
			currentElement->setText(empty);
			currentElement->setNamed(false);
		}
	}
	for (std::shared_ptr<SignalTrack> currentElement : signalTrackList)
	{
		if (currentElement->getText() == textToDelete)
		{
			currentElement->setText(empty);
			currentElement->setNamed(false);
		}
	}
	for (std::shared_ptr<BridgeUnderpassTrack> currentElement : bridgeUnderpassTrackList)
	{
		if (currentElement->getText() == textToDelete)
		{
			currentElement->setText(empty);
			currentElement->setNamed(false);
		}
	}
	for (std::shared_ptr<SwitchTrack> currentElement : switchTrackList)
	{
		if (currentElement->getText() == textToDelete)
		{
			currentElement->setText(empty);
			currentElement->setNamed(false);
		}
	}
	for (std::shared_ptr<CrossoverTrack> currentElement : crossoverTrackList)
	{
		if (currentElement->getText() == textToDelete)
		{
			currentElement->setText(empty);
			currentElement->setNamed(false);
		}
	}
	for (std::shared_ptr<FlyoverTrack> currentElement : flyoverTrackList)
	{
		if (currentElement->getText() == textToDelete)
		{
			currentElement->setText(empty);
			currentElement->setNamed(false);
		}
	}
	for (std::shared_ptr<NamedLocation> currentElement : namedLocationList)
	{
		if (currentElement->getText() == textToDelete)
		{
			currentElement->setText(empty);
			currentElement->setNamed(false);
		}
	}
	for (std::shared_ptr<Concourse> currentElement : concourseList)
	{
		if (currentElement->getText() == textToDelete)
		{
			currentElement->setText(empty);
			currentElement->setNamed(false);
		}
	}
}

std::shared_ptr<Text> Map::getTextToMove() const
{
	return textToMove;
}

bool Map::setTextToMove(int exactX, int exactY)
{
	if (checkTextExists(exactX, exactY))
	{
		textToMove = getTextAt(exactX, exactY);
		return true;
	}
	textToMove = nullptr;
	return false;
}

void Map::setTextToMove(const std::shared_ptr<Text> &newTextToMove)
{
	textToMove = newTextToMove;
}

void Map::moveText(int exactX, int exactY)
{

	if (textToMove != nullptr)
	{
		int fontSize = textToMove->getFontSize();
		textToMove->setLocationX(exactX);
		textToMove->setLocationY(exactY);
		textToMove->setEditableX(exactX+fontSize);
		textToMove->setEditableY(exactY+fontSize);
	}

}

void Map::changeDeleteText(QString readableBit, bool ok, std::shared_ptr<Text> text)
{
	if (readableBit.startsWith(" "))
	{
		readableBit.clear();
	}
	if(!readableBit.isEmpty() && ok)
	{

		text->setReadableText(readableBit);
	}
	else
	{
		deleteTextFromAllElements(text);
		deleteText(text);
	}
}

void Map::linkLocalText(int locationX, int locationY, std::shared_ptr<Text> linkedText)
{
	if (checkElementExists(locationX, locationY))
	{
		//Get whatever is at that location
		std::shared_ptr<StraightTrack> track = getTrackHasPlatformAt(locationX,locationY);
		std::shared_ptr<Concourse> concourse = getConcourseAt(locationX, locationY);
		std::shared_ptr<NamedLocation> namedLocation = getNamedLocationAt(locationX, locationY);
		std::shared_ptr<BridgeUnderpassTrack> bridgeUnderpassTrack = getBridgeUnderpassTrack(locationX, locationY);
		//link text to it
		if (bridgeUnderpassTrack != nullptr)
		{
			if (!bridgeUnderpassTrack->getNamed())
			{
				bridgeUnderpassTrack->setText(linkedText);
				bridgeUnderpassTrack->setNamed(true);
			}
		}
		if (track != nullptr)
		{
			if (track->getPlatformAny())
			{
				track->setText(linkedText);
				track->setNamed(true);
			}
		}
		if (concourse != nullptr)
		{
			if (!concourse->getNamed())
			{
				concourse->setText(linkedText);
				concourse->setNamed(true);
			}
		}
		if (namedLocation != nullptr)
		{
			if (!namedLocation->getNamed())
			{
				namedLocation->setText(linkedText);
				namedLocation->setNamed(true);
			}
		}
		if (track != nullptr || concourse != nullptr)
		{
			//See if there's a track above it
			if (checkElementExists(locationX, locationY+16))
			{
				std::shared_ptr<StraightTrack> trackTempYP16 = getTrackHasPlatformAt(locationX,locationY+16);
				std::shared_ptr<Concourse> concourseTempYP16 = getConcourseAt(locationX,locationY+16);
				std::shared_ptr<BridgeUnderpassTrack> bridgeUnderpassTempYP16 = getBridgeUnderpassTrack(locationX,locationY+16);
				//Try link the track to text if it has a platform.
				//Try link if the the element isn't named yet.
				if (trackTempYP16 != nullptr)
				{
					if (trackTempYP16->getPlatformAny())
					{
						if (!trackTempYP16->getNamed())
						{
							//Link it if there's a track there and it hasn't been named
							linkLocalText(locationX, locationY+16, linkedText);
						}
					}
				}
				else if (concourseTempYP16 != nullptr)
				{
					if (!concourseTempYP16->getNamed())
					{
						linkLocalText(locationX, locationY+16, linkedText);
					}
				}
				if (bridgeUnderpassTempYP16 != nullptr)
				{
					if (!bridgeUnderpassTempYP16->getNamed())
					{
						linkLocalText(locationX, locationY+16, linkedText);
					}
				}
			}
			//See if there's a track underneath
			if (checkElementExists(locationX, locationY-16))
			{
				std::shared_ptr<StraightTrack> trackTempYM16 = getTrackHasPlatformAt(locationX,locationY-16);
				std::shared_ptr<Concourse> concourseTempYM16 = getConcourseAt(locationX,locationY-16);
				std::shared_ptr<BridgeUnderpassTrack> bridgeUnderpassTempYM16 = getBridgeUnderpassTrack(locationX,locationY-16);

				if (trackTempYM16 != nullptr)
				{
					if (trackTempYM16->getPlatformAny())
					{
						if (!trackTempYM16->getNamed())
						{
							linkLocalText(locationX, locationY-16, linkedText);
						}
					}
				}
				else if (concourseTempYM16 != nullptr)
				{
					if (!concourseTempYM16->getNamed())
					{
						linkLocalText(locationX, locationY-16, linkedText);
					}
				}
				if (bridgeUnderpassTempYM16 != nullptr)
				{
					if (!bridgeUnderpassTempYM16->getNamed())
					{
						linkLocalText(locationX, locationY-16, linkedText);
					}
				}

			}
			//See if there's a track on the right of it
			if (checkElementExists(locationX+16, locationY))
			{
				std::shared_ptr<StraightTrack> trackTempXP16 = getTrackHasPlatformAt(locationX+16,locationY);
				std::shared_ptr<Concourse> concourseTempXP16 = getConcourseAt(locationX+16,locationY);
				std::shared_ptr<BridgeUnderpassTrack> bridgeUnderpassTempXP16 = getBridgeUnderpassTrack(locationX+16,locationY);

				if (trackTempXP16 != nullptr)
				{
					if (trackTempXP16->getPlatformAny())
					{
						if (!trackTempXP16->getNamed())
						{
							linkLocalText(locationX+16, locationY, linkedText);
						}
					}
				}
				else if (concourseTempXP16 != nullptr)
				{
					if (!concourseTempXP16->getNamed())
					{
						linkLocalText(locationX+16, locationY, linkedText);
					}
				}
				if (bridgeUnderpassTempXP16 != nullptr)
				{
					if (!bridgeUnderpassTempXP16->getNamed())
					{
						linkLocalText(locationX+16, locationY, linkedText);
					}
				}
			}
			//See if there's a track on the left of it
			if (checkElementExists(locationX-16, locationY))
			{
				std::shared_ptr<StraightTrack> trackTempXM16 = getTrackHasPlatformAt(locationX-16,locationY);
				std::shared_ptr<Concourse> concourseTempXM16 = getConcourseAt(locationX-16,locationY);
				std::shared_ptr<BridgeUnderpassTrack> bridgeUnderpassTempXM16 = getBridgeUnderpassTrack(locationX-16,locationY);
				if (trackTempXM16 != nullptr)
				{
					if (trackTempXM16->getPlatformAny())
					{
						if (!trackTempXM16->getNamed())
						{
							linkLocalText(locationX-16, locationY, linkedText);
						}
					}
				}
				else if (concourseTempXM16 != nullptr)
				{
					if (!concourseTempXM16->getNamed())
					{
						linkLocalText(locationX-16, locationY, linkedText);
					}
				}
				if (bridgeUnderpassTempXM16 != nullptr)
				{
					if (!bridgeUnderpassTempXM16->getNamed())
					{
						linkLocalText(locationX-16, locationY, linkedText);
					}
				}
			}
		}
		//Same for namedLocation.
		else
		{
			if (checkElementExists(locationX, locationY+16))
			{
				std::shared_ptr<NamedLocation> namedLocationTempYP16 = getNamedLocationAt(locationX,locationY+16);
				if (namedLocationTempYP16 != nullptr)
				{
					if (!namedLocationTempYP16->getNamed())
					{
						linkLocalText(locationX, locationY+16, linkedText);
					}
				}
			}
			if (checkElementExists(locationX, locationY-16))
			{
				std::shared_ptr<NamedLocation> namedLocationYM16 = getNamedLocationAt(locationX,locationY-16);

				if (namedLocationYM16 != nullptr)
				{
					if (!namedLocationYM16->getNamed())
					{
						linkLocalText(locationX, locationY-16, linkedText);
					}
				}
			}
			if (checkElementExists(locationX+16, locationY))
			{
				std::shared_ptr<NamedLocation> namedLocationXP16 = getNamedLocationAt(locationX+16,locationY);
				if (namedLocationXP16 != nullptr)
				{
					if (!namedLocationXP16->getNamed())
					{
						linkLocalText(locationX+16, locationY, linkedText);
					}
				}
			}
			if (checkElementExists(locationX-16, locationY))
			{
				std::shared_ptr<NamedLocation> namedLocationTempXM16 = getNamedLocationAt(locationX-16,locationY);
				if (namedLocationTempXM16 != nullptr)
				{
					if (!namedLocationTempXM16->getNamed())
					{
						linkLocalText(locationX-16, locationY, linkedText);
					}
				}
			}
		}
	}
}

//Platform related methods

void Map::addPlatform(Platform side, int locationX, int locationY)
{
	bool added = false;
	if (!straightTrackList.empty() && added == false)
	{
		for (std::shared_ptr<StraightTrack>& currentElement : straightTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			bool levelCrossing = currentElement->hasLevelCrossing();
			if (currentX == locationX && currentY == locationY)
			{
				if (!levelCrossing)
				{
					switch (side)
					{
						case Platform::UP:
						{
							if (currentElement->getStraightType() == StraightType::STRAIGHTH)
							{
								currentElement->setPlatform1(true);
								added = true;
							}
							break;
						}
						case Platform::DOWN:
						{
							if (currentElement->getStraightType() == StraightType::STRAIGHTH)
							{
								currentElement->setPlatform2(true);
								added = true;
							}
							break;
						}
						case Platform::LEFT:
						{
							if (currentElement->getStraightType() == StraightType::STRAIGHTV)
							{
								currentElement->setPlatform1(true);
								added = true;
							}
							break;
						}
						case Platform::RIGHT:
						{
							if (currentElement->getStraightType() == StraightType::STRAIGHTV)
							{
								currentElement->setPlatform2(true);
								added = true;
							}
							break;
						}
					}
				}
				if (added)
				{
					currentElement->setPlatformAny(true);
				}
			}
		}
	}
	if (!directedTrackList.empty() && added == false)
	{
		for (std::shared_ptr<DirectedTrack>& currentElement : directedTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				switch (side)
				{
					case Platform::LEFT:
					{
						if (currentElement->getDirectType() == DirectedType::DIRECTEDUP)
						{
							currentElement->setPlatform1(true);
						}
						else if (currentElement->getDirectType() == DirectedType::DIRECTEDDOWN)
						{
							currentElement->setPlatform1(true);
						}
						added = true;
						break;
					}
					case Platform::RIGHT:
					{
						if (currentElement->getDirectType() == DirectedType::DIRECTEDUP)
						{
							currentElement->setPlatform2(true);
						}
						else if (currentElement->getDirectType() == DirectedType::DIRECTEDDOWN)
						{
							currentElement->setPlatform2(true);
						}
						added = true;
						break;
					}
					case Platform::UP:
					{
						if (currentElement->getDirectType() == DirectedType::DIRECTEDLEFT)
						{
							currentElement->setPlatform1(true);
						}
						else if (currentElement->getDirectType() == DirectedType::DIRECTEDRIGHT)
						{
							currentElement->setPlatform1(true);
						}
						added = true;
						break;
					}
					case Platform::DOWN:
					{
						if (currentElement->getDirectType() == DirectedType::DIRECTEDLEFT)
						{
							currentElement->setPlatform2(true);
						}
						else if (currentElement->getDirectType() == DirectedType::DIRECTEDRIGHT)
						{
							currentElement->setPlatform2(true);
						}
						added = true;
						break;
					}
					default:
					{
						added = false;
						break;
					}
				}
			}
			if (added)
			{
				currentElement->setPlatformAny(true);
			}
		}
	}
	if (!bufferTrackList.empty() && added == false)
	{
		for (std::shared_ptr<BufferTrack>& currentElement : bufferTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				switch (side)
				{
					case Platform::LEFT:
					{
						if (currentElement->getBufferType() == BufferType::BUFFERUP)
						{
							currentElement->setPlatform1(true);
						}
						else if (currentElement->getBufferType() == BufferType::BUFFERDOWN)
						{
							currentElement->setPlatform1(true);
						}
						added = true;
						break;
					}
					case Platform::RIGHT:
					{
						if (currentElement->getBufferType() == BufferType::BUFFERUP)
						{
							currentElement->setPlatform2(true);
						}
						else if (currentElement->getBufferType() == BufferType::BUFFERDOWN)
						{
							currentElement->setPlatform2(true);
						}
						added = true;
						break;
					}
					case Platform::UP:
					{
						if (currentElement->getBufferType() == BufferType::BUFFERLEFT)
						{
							currentElement->setPlatform1(true);
						}
						else if (currentElement->getBufferType() == BufferType::BUFFERRIGHT)
						{
							currentElement->setPlatform1(true);
						}
						added = true;
						break;
					}
					case Platform::DOWN:
					{
						if (currentElement->getBufferType() == BufferType::BUFFERLEFT)
						{
							currentElement->setPlatform2(true);
						}
						else if (currentElement->getBufferType() == BufferType::BUFFERRIGHT)
						{
							currentElement->setPlatform2(true);
						}
						added = true;
						break;
					}
					default:
					{
						added = false;
					}
				}
			}
			if (added)
			{
				currentElement->setPlatformAny(true);
			}
	}
	}
	if (!signalTrackList.empty() && added == false)
	{
		for (std::shared_ptr<SignalTrack>& currentElement : signalTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				switch (side)
				{
					case Platform::LEFT:
					{
						if (currentElement->getSignalType() == SignalType::SIGNALUP)
						{
							currentElement->setPlatform1(true);
						}
						else if (currentElement->getSignalType() == SignalType::SIGNALDOWN)
						{
							currentElement->setPlatform1(true);
						}
						added = true;
						break;
					}
					case Platform::RIGHT:
					{
						if (currentElement->getSignalType() == SignalType::SIGNALUP)
						{
							currentElement->setPlatform2(true);
						}
						else if (currentElement->getSignalType() == SignalType::SIGNALDOWN)
						{
							currentElement->setPlatform2(true);
						}
						added = true;
						break;
					}
					case Platform::UP:
					{
						if (currentElement->getSignalType() == SignalType::SIGNALLEFT)
						{
							currentElement->setPlatform1(true);
						}
						else if (currentElement->getSignalType() == SignalType::SIGNALRIGHT)
						{
							currentElement->setPlatform1(true);
						}
						added = true;
						break;
					}
					case Platform::DOWN:
					{
						if (currentElement->getSignalType() == SignalType::SIGNALLEFT)
						{
							currentElement->setPlatform2(true);
						}
						else if (currentElement->getSignalType() == SignalType::SIGNALRIGHT)
						{
							currentElement->setPlatform2(true);
						}
						added = true;
						break;
					}
					default:
					{
						added = false;
					}
				}
			}
			if (added)
			{
				currentElement->setPlatformAny(true);
			}
	}
	}
	if (!bridgeUnderpassTrackList.empty() && added == false)
	{
		for (std::shared_ptr<BridgeUnderpassTrack>& currentElement : bridgeUnderpassTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				switch (side)
				{
					case Platform::LEFT:
					{
						if (currentElement->getBridgeUnderpassType() == BridgeUnderpassType::BRIDGE2)
						{
						   currentElement->setPlatform1(true);
						}
						else if (currentElement->getBridgeUnderpassType() == BridgeUnderpassType::UNDERPASS2)
						{
							currentElement->setPlatform1(true);
						}
						added = true;
						break;
					}
					case Platform::RIGHT:
					{
						if (currentElement->getBridgeUnderpassType() == BridgeUnderpassType::BRIDGE2)
						{
							currentElement->setPlatform2(true);
						}
						else if (currentElement->getBridgeUnderpassType() == BridgeUnderpassType::UNDERPASS2)
						{
							currentElement->setPlatform2(true);
						}
						added = true;
						break;
					}
					case Platform::UP:
					{
						if (currentElement->getBridgeUnderpassType() == BridgeUnderpassType::BRIDGE1)
						{
							currentElement->setPlatform1(true);
						}
						else if (currentElement->getBridgeUnderpassType() == BridgeUnderpassType::UNDERPASS1)
						{
							currentElement->setPlatform1(true);
						}
						added = true;
						break;
					}
					case Platform::DOWN:
					{
						if (currentElement->getBridgeUnderpassType() == BridgeUnderpassType::BRIDGE1)
						{
							currentElement->setPlatform2(true);
						}
						else if (currentElement->getBridgeUnderpassType() == BridgeUnderpassType::UNDERPASS1)
						{
							currentElement->setPlatform2(true);
						}
						added = true;
						break;
					}
					default:
					{
						added = false;
					}
				}
			}
			if (added)
			{
				currentElement->setPlatformAny(true);
			}
		}
	}
	if (!switchTrackList.empty() && added == false)
	{
		for (std::shared_ptr<SwitchTrack>& currentElement : switchTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				switch (currentElement->getSwitchType())
				{
					case SwitchType::SWITCHTIGHT1:
					case SwitchType::SWITCHTIGHT2:
					case SwitchType::SWITCH1:
					case SwitchType::SWITCH2:
					{
						if (side == Platform::DOWN)
						{
							currentElement->setPlatform2(true);
							added = true;
						}
						break;
					}
					case SwitchType::SWITCHTIGHT3:
					case SwitchType::SWITCHTIGHT4:
					case SwitchType::SWITCH3:
					case SwitchType::SWITCH4:
					{
						if (side == Platform::UP)
						{
							currentElement->setPlatform1(true);
							added = true;
						}
						break;
					}
					case SwitchType::SWITCHTIGHT5:
					case SwitchType::SWITCHTIGHT7:
					case SwitchType::SWITCH5:
					case SwitchType::SWITCH7:
					{
						if (side == Platform::RIGHT)
						{
							currentElement->setPlatform2(true);
							added = true;
						}
						break;
					}
					case SwitchType::SWITCHTIGHT6:
					case SwitchType::SWITCHTIGHT8:
					case SwitchType::SWITCH6:
					case SwitchType::SWITCH8:
					{
						if (side == Platform::LEFT)
						{
							currentElement->setPlatform1(true);
							added = true;
						}
						break;
					}
					case SwitchType::SWITCHSPLIT1:
					case SwitchType::SWITCHSPLIT2:
					case SwitchType::SWITCHSPLIT3:
					case SwitchType::SWITCHSPLIT4:
					case SwitchType::SWITCHSPLIT5:
					case SwitchType::SWITCHSPLIT6:
					case SwitchType::SWITCHSPLIT7:
					case SwitchType::SWITCHSPLIT8:
					case SwitchType::SWITCH9:
					case SwitchType::SWITCH10:
					case SwitchType::SWITCH11:
					case SwitchType::SWITCH12:
					case SwitchType::SWITCH13:
					case SwitchType::SWITCH14:
					case SwitchType::SWITCH15:
					case SwitchType::SWITCH16:
					{
						break;
					}
				}
			}
			if (added)
			{
				currentElement->setPlatformAny(true);
			}
		}
	}
}

void Map::addLevelCrossing(int locationX, int locationY)
{
	for (int i = 0; i < straightTrackList.size(); i++)
		{
			std::shared_ptr<StraightTrack>& currentElement = straightTrackList[i];
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			bool platform1 = currentElement->getPlatform1();
			bool platform2 = currentElement->getPlatform2();
			if (currentX == locationX && currentY == locationY)
			{
				if (!platform1 && !platform2)
				{
					currentElement->addLevelCrossing();
				}
			}
	}
}

//Deleting methods

bool Map::deleteElement(int locationX, int locationY)
{
	bool deleted = false;
	if (!deleted)
	{
		deleted = removeStraightTrack(locationX, locationY);
	}
	if (!deleted)
	{
		deleted = removeDirectedTrack(locationX, locationY);
	}
	if (!deleted)
	{
		deleted = removeCurvedTrack(locationX, locationY);
	}
	if (!deleted)
	{
		deleted = removeLinkedTrack(locationX, locationY);
	}
	if (!deleted)
	{
		deleted = removeExitTrack(locationX, locationY);
	}
	if (!deleted)
	{
		deleted = removeBufferTrack(locationX, locationY);
	}
	if (!deleted)
	{
		deleted = removeSignalTrack(locationX, locationY);
	}
	if (!deleted)
	{
		deleted = removeBridgeUnderpassTrack(locationX, locationY);
	}
	if (!deleted)
	{
		deleted = removeSwitchTrack(locationX, locationY);
	}
	if (!deleted)
	{
		deleted = removeCrossoverTrack(locationX, locationY);
	}
	if (!deleted)
	{
		deleted = removeFlyoverTrack(locationX, locationY);
	}
	if (!deleted)
	{
		deleted = removeNamedLocation(locationX, locationY);
	}
	if (!deleted)
	{
		deleted = removeConcourse(locationX, locationY);
	}
	if (!deleted)
	{
		deleted = removeParapet(locationX, locationY);
	}
	return deleted;
}

std::shared_ptr<Element> Map::getElementAt(int locationX, int locationY)
{
	bool found = false;
	std::shared_ptr<Element> element = nullptr;
	if (!namedLocationList.empty())
	{
		for (std::shared_ptr<NamedLocation>& currentElement : namedLocationList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				element = currentElement;
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
				element = currentElement;
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
				element = currentElement;
				found = true;
			}
		}
	}
	return element;
}

std::shared_ptr<NamedElement> Map::getNamedElementAt(int locationX, int locationY)
{
	bool found = false;
	std::shared_ptr<NamedElement> element = nullptr;
	if (!namedLocationList.empty())
	{
		for (std::shared_ptr<NamedLocation>& currentElement : namedLocationList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				element = currentElement;
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
				element = currentElement;
				found = true;
			}
		}
	}
	return element;
}

std::shared_ptr<Track> Map::getTrackAt(int locationX, int locationY)
{
	bool found = false;
	std::shared_ptr<Track> track = nullptr;

	if (!straightTrackList.empty())
	{
		for (std::shared_ptr<StraightTrack>& currentTrack : straightTrackList)
		{
			int currentX = currentTrack->getLocationX();
			int currentY = currentTrack->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				track = currentTrack;
				found = true;
			}
		}
	}

	if (!directedTrackList.empty() && found == false)
	{
		for (std::shared_ptr<DirectedTrack>& currentTrack : directedTrackList)
		{
			int currentX = currentTrack->getLocationX();
			int currentY = currentTrack->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				track = currentTrack;
				found = true;
			}
		}
	}

	if (!curvedTrackList.empty() && found == false)
	{
		for (std::shared_ptr<CurvedTrack>& currentTrack : curvedTrackList)
		{

			int currentX = currentTrack->getLocationX();
			int currentY = currentTrack->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				track = currentTrack;
				found = true;
			}
		}
	}

	if (!linkedTrackList.empty() && found == false)
	{
		for (std::shared_ptr<LinkedTrack>& currentTrack : linkedTrackList)
		{

			int currentX = currentTrack->getLocationX();
			int currentY = currentTrack->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				track = currentTrack;
				found = true;
			}
		}
	}

	if (!exitTrackList.empty() && found == false)
	{
		for (std::shared_ptr<ExitTrack>& currentTrack : exitTrackList)
		{

			int currentX = currentTrack->getLocationX();
			int currentY = currentTrack->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				track = currentTrack;
				found = true;
			}
		}
	}

	if (!bufferTrackList.empty() && found == false)
	{
		for (std::shared_ptr<BufferTrack>& currentTrack : bufferTrackList)
		{

			int currentX = currentTrack->getLocationX();
			int currentY = currentTrack->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				track = currentTrack;
				found = true;
			}
		}
	}

	if (!signalTrackList.empty() && found == false)
	{
		for (std::shared_ptr<SignalTrack>& currentTrack : signalTrackList)
		{

			int currentX = currentTrack->getLocationX();
			int currentY = currentTrack->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				track = currentTrack;
				found = true;
			}
		}
	}

	if (!bridgeUnderpassTrackList.empty() && found == false)
	{
		for (std::shared_ptr<BridgeUnderpassTrack>& currentTrack : bridgeUnderpassTrackList)
		{
			int currentX = currentTrack->getLocationX();
			int currentY = currentTrack->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				track = currentTrack;
				found = true;
			}
		}
	}

	if (!switchTrackList.empty() && found == false)
	{
		for (std::shared_ptr<SwitchTrack>& currentTrack : switchTrackList)
		{

			int currentX = currentTrack->getLocationX();
			int currentY = currentTrack->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				track = currentTrack;
				found = true;
			}
		}
	}

	if (!crossoverTrackList.empty() && found == false)
	{
		for (std::shared_ptr<CrossoverTrack>& currentTrack : crossoverTrackList)
		{

			int currentX = currentTrack->getLocationX();
			int currentY = currentTrack->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				track = currentTrack;
				found = true;
			}
		}
	}

	if (!flyoverTrackList.empty() && found == false)
	{
		for (std::shared_ptr<FlyoverTrack>& currentTrack : flyoverTrackList)
		{

			int currentX = currentTrack->getLocationX();
			int currentY = currentTrack->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				track = currentTrack;
				found = true;
			}
		}
	}
	return track;
}

std::shared_ptr<StraightTrack> Map::getTrackHasPlatformAt(int locationX, int locationY)
{
	bool found = false;
	std::shared_ptr<StraightTrack> track = nullptr;
	if (!straightTrackList.empty())
	{
		for (std::shared_ptr<StraightTrack>& currentTrack : straightTrackList)
		{
			int currentX = currentTrack->getLocationX();
			int currentY = currentTrack->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				track = currentTrack;
				found = true;
			}
		}
	}
	if (!directedTrackList.empty() && found == false)
	{
		for (std::shared_ptr<DirectedTrack>& currentTrack : directedTrackList)
		{
			int currentX = currentTrack->getLocationX();
			int currentY = currentTrack->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				track = currentTrack;
				found = true;
			}
		}
	}
	if (!bufferTrackList.empty() && found == false)
	{
		for (std::shared_ptr<BufferTrack>& currentTrack : bufferTrackList)
		{

			int currentX = currentTrack->getLocationX();
			int currentY = currentTrack->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				track = currentTrack;
				found = true;
			}
		}
	}
	if (!signalTrackList.empty() && found == false)
	{
		for (std::shared_ptr<SignalTrack>& currentTrack : signalTrackList)
		{

			int currentX = currentTrack->getLocationX();
			int currentY = currentTrack->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				track = currentTrack;
				found = true;
			}
		}
	}
	if (!switchTrackList.empty() && found == false)
	{
		for (std::shared_ptr<SwitchTrack>& currentTrack : switchTrackList)
		{

			int currentX = currentTrack->getLocationX();
			int currentY = currentTrack->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				track = currentTrack;
				found = true;
			}
		}
	}
	return track;
}

//General methods


std::vector<std::shared_ptr<Track> > Map::getTrackList() const
{
	return trackList;
}

void Map::setTrackList(const std::vector<std::shared_ptr<Track> > &newTrackList)
{
	trackList = newTrackList;
}

void Map::makeTrackList()
{
	std::vector<std::shared_ptr<Track>> tempTrackList;
	if (!straightTrackList.empty())
	{
		for (std::shared_ptr<Track> track : straightTrackList)
		{
			tempTrackList.push_back(track);
		}
	}
	if (!directedTrackList.empty())
	{
		for (std::shared_ptr<Track> track : directedTrackList)
		{
			tempTrackList.push_back(track);
		}
	}
	if (!curvedTrackList.empty())
	{
		for (std::shared_ptr<Track> track : curvedTrackList)
		{
			tempTrackList.push_back(track);
		}
	}
	if (!linkedTrackList.empty())
	{
		for (std::shared_ptr<Track> track : linkedTrackList)
		{
			tempTrackList.push_back(track);
		}
	}
	if (!exitTrackList.empty())
	{
		for (std::shared_ptr<Track> track : exitTrackList)
		{
			tempTrackList.push_back(track);
		}
	}
	if (!bufferTrackList.empty())
	{
		for (std::shared_ptr<Track> track : bufferTrackList)
		{
			tempTrackList.push_back(track);
		}
	}
	if (!signalTrackList.empty())
	{
		for (std::shared_ptr<Track> track : signalTrackList)
		{
			tempTrackList.push_back(track);
		}
	}
	if (!bridgeUnderpassTrackList.empty())
	{
		for (std::shared_ptr<Track> track : bridgeUnderpassTrackList)
		{
			tempTrackList.push_back(track);
		}
	}
	if (!switchTrackList.empty())
	{
		for (std::shared_ptr<Track> track : switchTrackList)
		{
			tempTrackList.push_back(track);
		}
	}
	if (!crossoverTrackList.empty())
	{
		for (std::shared_ptr<Track> track : crossoverTrackList)
		{
			tempTrackList.push_back(track);
		}
	}
	if (!flyoverTrackList.empty())
	{
		for (std::shared_ptr<Track> track : flyoverTrackList)
		{
			tempTrackList.push_back(track);
		}
	}
	setTrackList(tempTrackList);
}

bool Map::checkAllTracksConnected()
{
	std::shared_ptr<Track> startTrack = findTopLeftTrack();
	makeTrackList();
	bool allConnected = true;
	allConnected = checkAllLinkTrackLinked();
	if (trackList.size() == 0)
	{
		Message::showZeroTrackErrorMessage();
	}
	else
	{
		if (allConnected)
		{
			for (std::shared_ptr<Track> currentTrack : trackList)
			{
				int centreTrackX = currentTrack->getLocationX();
				int centreTrackY = currentTrack->getLocationY();
				if (currentTrack->getLinkAt(0))
				{
					std::shared_ptr<Track> leftUpTrack = getTrackAt(centreTrackX-16, centreTrackY+16);
					if (leftUpTrack == nullptr)
					{
						allConnected = false;
					}
				}
				if (currentTrack->getLinkAt(1) && allConnected)
				{
					std::shared_ptr<Track> upTrack = getTrackAt(centreTrackX, centreTrackY+16);
					if (upTrack == nullptr)
					{
						allConnected = false;
					}
				}
				if (currentTrack->getLinkAt(2) && allConnected)
				{
					std::shared_ptr<Track> rightUpTrack = getTrackAt(centreTrackX+16, centreTrackY+16);
					if (rightUpTrack == nullptr)
					{
						allConnected = false;
					}
				}
				if (currentTrack->getLinkAt(3) && allConnected)
				{
					std::shared_ptr<Track> leftTrack = getTrackAt(centreTrackX-16, centreTrackY);
					if (leftTrack == nullptr)
					{
						allConnected = false;
					}
				}
				if (currentTrack->getLinkAt(5) && allConnected)
				{
					std::shared_ptr<Track> rightTrack = getTrackAt(centreTrackX+16, centreTrackY);
					if (rightTrack == nullptr)
					{
						allConnected = false;
					}
				}
				if (currentTrack->getLinkAt(6) && allConnected)
				{
					std::shared_ptr<Track> rightDownTrack = getTrackAt(centreTrackX-16, centreTrackY-16);
					if (rightDownTrack == nullptr)
					{
						allConnected = false;
					}
				}
				if (currentTrack->getLinkAt(7) && allConnected)
				{
					std::shared_ptr<Track> downTrack = getTrackAt(centreTrackX, centreTrackY-16);
					if (downTrack == nullptr)
					{
						allConnected = false;
					}
				}
				if (currentTrack->getLinkAt(8) && allConnected)
				{
					std::shared_ptr<Track> rightDownTrack = getTrackAt(centreTrackX+16, centreTrackY-16);
					if (rightDownTrack == nullptr)
					{
						allConnected = false;
					}
				}
			}
		}
		if (allConnected)
		{
			Message::showAllTrackConnecedSuccessMessage();
		}
		else
		{
			Message::showNotAllTrackConnectedErrorMessage();
		}
	}

	return allConnected;
}


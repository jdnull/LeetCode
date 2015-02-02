class Point:
	def __init__(self, a=0, b=0):
		self.x = a
		self.y = b

def initinit(a,b,ps):
	for i in range(0,a):
		for j in range(0,b):
			p = Point(i,j)
			ps.append(p)

def init(ps):
	psList = []
	for p in ps:
		psList.append(Point(p[0],p[1]))
	return psList

def MaxPoints(psList):
	if len(psList) == 0:
		maxNum = 0
	elif len(psList) == 1:
		maxNum = 1
	elif len(psList) == 2:
		maxNum = 2
	else:
		maxNum = 2
		for p in psList:
			slopeDict = {}
			redundancy = 0
			tempMax = 1
			for pp in psList:
				if p == pp: # skip itself
					continue
				if p.x == pp.x and p.y == pp.y: # calculate the redundancy
					redundancy += 1
					continue
				if p.x == pp.x and p.y != pp.y: # '*' for perpendicular line
					slope = "*"
				if p.x != pp.x: # slope as index of dict
					slope = (p.y - pp.y) * 1.0 / (p.x - pp.x)
				if slope in slopeDict:
					slopeDict[slope] += 1 # set the dict without the redundancy
					if slopeDict[slope] > tempMax:
						tempMax = slopeDict[slope]
				else:
					slopeDict[slope] = 2 # do not add the redundancy, prevent adding one more time
			if maxNum < tempMax + redundancy: # count the redundancy during outer cycle
				maxNum = tempMax + redundancy
	return maxNum

if __name__ == '__main__':
	# points = []
	# initinit(2,3,points)
	points = [(29,87),(145,227),(400,84),(800,179),(60,950),(560,122),(-6,5),(-87,-53),(-64,-118),(-204,-388),(720,160),(-232,-228),(-72,-135),(-102,-163),(-68,-88),(-116,-95),(-34,-13),(170,437),(40,103),(0,-38),(-10,-7),(-36,-114),(238,587),(-340,-140),(-7,2),(36,586),(60,950),(-42,-597),(-4,-6),(0,18),(36,586),(18,0),(-720,-182),(240,46),(5,-6),(261,367),(-203,-193),(240,46),(400,84),(72,114),(0,62),(-42,-597),(-170,-76),(-174,-158),(68,212),(-480,-125),(5,-6),(0,-38),(174,262),(34,137),(-232,-187),(-232,-228),(232,332),(-64,-118),(-240,-68),(272,662),(-40,-67),(203,158),(-203,-164),(272,662),(56,137),(4,-1),(-18,-233),(240,46),(-3,2),(640,141),(-480,-125),(-29,17),(-64,-118),(800,179),(-56,-101),(36,586),(-64,-118),(-87,-53),(-29,17),(320,65),(7,5),(40,103),(136,362),(-320,-87),(-5,5),(-340,-688),(-232,-228),(9,1),(-27,-95),(7,-5),(58,122),(48,120),(8,35),(-272,-538),(34,137),(-800,-201),(-68,-88),(29,87),(160,27),(72,171),(261,367),(-56,-101),(-9,-2),(0,52),(-6,-7),(170,437),(-261,-210),(-48,-84),(-63,-171),(-24,-33),(-68,-88),(-204,-388),(40,103),(34,137),(-204,-388),(-400,-106)]
	# points = [(0,0),(1,1),(0,0)]
	# points = [(1,1),(1,1),(1,1)]
	# points = [(0,0),(0,0)]
	# points = [(1,1),(1,1),(2,2),(2,2)]
	points = init(points)
	print(MaxPoints(points))











number_of_classes = 100

for i in range(number_of_classes, 0, -1):

    print("class Generated{}(Generated{}):\n\tdef __init__(self):\n\t\tGenerated{}.__init__(self)\n\t\tself.num{} = 5\n\n".format(i, i+1, i+1, i))

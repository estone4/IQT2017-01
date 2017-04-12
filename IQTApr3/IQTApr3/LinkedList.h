

struct family
{
	int index;
	char *name;
	char *initials;
	int age;
	struct family * next_ptr;
	struct family * previous_ptr;
};

int link_my_struct(struct family ** myArray, int numOfNodes);

int print_the_struct(struct family * headNode);

struct family * add_a_struct(struct family * headnode, struct family * addThisNode, int addAtThisPosition);

void clear_list(struct family * headnode);

struct family * create_node(int index, char *name, char *initials, int age);



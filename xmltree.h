#ifndef XML_TREE
#define XML_TREE

struct Attribute {
	char* name;
	char* value;
};

struct XMLNode {
	int child_count;
	struct XMLNode** children;
	char* tag;
	char* data;
	int attrs_count;
	struct Attribute** attrs;
};

void addChildnode(struct XMLNode*, struct XMLNode*);
struct XMLNode* createNode(char*, char*);
void generateXML(struct XMLNode*, int);
void freeTree(struct XMLNode*);
void addAttribute(struct XMLNode*, struct Attribute*);

struct Attribute* createAttribute(char*, char*);


#endif

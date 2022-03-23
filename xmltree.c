#include <stdio.h>
#include <stdlib.h>

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


struct XMLNode* createNode(char* tag, char* data) {
	struct XMLNode* node = malloc(sizeof(struct XMLNode));
	node->data = malloc(sizeof(data));
	node->data = data;
	node->tag = malloc(sizeof(tag));
	node->tag = tag;
	node->child_count = 0;
	node->children = NULL;
	node->attrs_count = 0;
	node->attrs = NULL;
	return node;
}

void addChildnode(struct XMLNode* parent, struct XMLNode* child) {
	parent->child_count++;
	parent->children = realloc(parent->children,
			   parent->child_count * sizeof(struct XMLNode*));
	parent->children[parent->child_count-1] = child;
};

void generateXML(struct XMLNode* node, int nesting_level) {
	printf("<%s", node->tag);
	for (int i = 0; i < node->attrs_count; i++) {
		struct Attribute* attr = node->attrs[i];
		printf("1");
		printf(" %s=\"%s\"", attr->name, attr->value);
	}
	printf(">");
	if (node->data)
		printf("%s", node->data);
	for (int i = 0; i < node->child_count; i++) {
		generateXML(node->children[i], nesting_level+1);
	}
	printf("</%s>", node->tag);
};

void freeTree(struct XMLNode* root) {
	for (int i = 0; i < root->child_count; i++) freeTree(root->children[i]);
	for (int i = 0; i < root->attrs_count; i++) free(root->attrs[i]);
	free(root);
}

void addAttribute(struct XMLNode* node, struct Attribute* attr) {
	node->attrs_count++;
	node->attrs = realloc(node->attrs,
		      node->attrs_count * sizeof(struct Attribute*));
	node->attrs[node->attrs_count-1] = attr;
};

struct Attribute* createAttribute(char* name, char* value) {
	struct Attribute* attr = malloc(sizeof(struct Attribute));
	attr->name = malloc(sizeof(name));
	attr->name = name;
	attr->value = malloc(sizeof(value));
	attr->value = value;
	return attr;
};

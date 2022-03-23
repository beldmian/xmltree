# xmltree
A small C library to generate XML data from tree structure

## Example usage

```c
struct XMLNode *tree = createNode("div", NULL);
struct XMLNode *child1 = createNode("ul", NULL);
struct XMLNode *child2 = createNode("h1", "Hello!");
struct XMLNode *child3 = createNode("li", "list 1");

struct Attribute *class1 = createAttribute("class", "containter");

addChildnode(tree, child1);
addChildnode(tree, child2);
addChildnode(child1, child3);

addAttribute(tree, class1);

// Will print "<div1 class="containter"><ul><li>list 1</li></ul><h1>Hello!</h1></div>"
generateXML(tree, 0);

freeTree(tree);
```


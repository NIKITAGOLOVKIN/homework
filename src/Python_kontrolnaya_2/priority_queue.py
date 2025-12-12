class BinomialHeap:
    def __init__(self):
        self.trees = []

    def merge(self, other_heap):
        trees = self.trees + other_heap.trees
        trees.sort(key=lambda x: x.order)
        new_trees = []
        carry = None
        i = 0
        while i < len(trees) or carry is not None:
            current_order = None
            if carry is not None:
                if i < len(trees):
                    current_order = min(carry.order, trees[i].order)
                else:
                    current_order = carry.order
            else:
                if i < len(trees):
                    current_order = trees[i].order
                else:
                    break

            current_list = []
            count = 0

            if carry is not None and carry.order == current_order:
                current_list.append(carry)
                carry = None
                count += 1

            while i < len(trees) and trees[i].order == current_order:
                current_list.append(trees[i])
                i += 1
                count += 1

            if count == 1:
                new_trees.append(current_list[0])
            elif count == 2:
                carry = merge_trees(current_list[0], current_list[1])
            elif count == 3:
                new_trees.append(current_list[0])
                carry = merge_trees(current_list[1], current_list[2])
        self.trees = new_trees

    def insert(self, key):
        new_heap = BinomialHeap()
        new_node = BinomialNode(key)
        new_heap.trees = [new_node]
        self.merge(new_heap)

    def extract_min(self):
        if not self.trees:
            return None

        min_index = 0
        for i in range(1, len(self.trees)):
            if self.trees[i].key < self.trees[min_index].key:
                min_index = i
        min_tree = self.trees.pop(min_index)

        child_heap = BinomialHeap()
        child_heap.trees = min_tree.children
        self.merge(child_heap)

        return min_tree.key

class BinomialNode:
    def __init__(self, key):
        self.key = key
        self.order = 0
        self.children = []

def merge_trees(tree1, tree2):
    if tree1.key > tree2.key:
        tree1, tree2 = tree2, tree1

    tree1.children.append(tree2)
    tree1.order += 1
    return tree1

a = BinomialHeap()
a.insert(67)
a.insert(42)
a.insert(52)
a.insert(999)
a.insert(228)
a.insert(339)
a.insert(111)
a.insert(666)
a.insert(777)
print(a.extract_min()
class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def build_balanced(values, start, end):
    if start > end:
        return None
    mid = (start + end) // 2
    node = Node(values[mid])
    node.left  = build_balanced(values, start, mid - 1)
    node.right = build_balanced(values, mid + 1, end)
    return node

def inorder(node, result=None):
    if result is None:
        result = []
    if node:
        inorder(node.left, result)
        result.append(node.value)
        inorder(node.right, result)
    return result

def print_tree(node, level=0, prefix="Корень: "):
    if node is None:
        return
    print(" " * (level * 4) + prefix + str(node.value))
    if node.left or node.right:
        if node.left:
            print_tree(node.left,  level + 1, "Л: ")
        else:
            print(" " * ((level + 1) * 4) + "Л: None")
        if node.right:
            print_tree(node.right, level + 1, "П: ")
        else:
            print(" " * ((level + 1) * 4) + "П: None")

if __name__ == '__main__':
    n = int(input("Введите число вершин (1–10): "))
    n = max(1, min(10, n))
    values = list(range(1, n + 1))
    root = build_balanced(values, 0, n - 1)
    print_tree(root)
    print("Обход in-order:", inorder(root))
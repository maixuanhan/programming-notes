## Solution

- Use pre-order traversal method to serialize the tree so that it will be easier to create a new tree when deserialize function is called.
- Since the type of data is string, a length is needed to track the data size.
- Delimeter is a single space. Because of the length, data may contain any OS supported characters.
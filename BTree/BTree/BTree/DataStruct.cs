using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BTree
{
    public class IntegerNode
    {
        public int NodeContent { get; set; }
        public IntegerNode Left { get; set; }
        public IntegerNode Right { get; set; }

        public IntegerNode(int cont)
        {
            NodeContent = cont;
            Left = null;
            Right = null;
        }
    }

    public class IntegerBST
    {
        private int size;
		int nodeNumber = 0;
		public int Count
        {
            get
            {
                return size;
            }
        }

        public IntegerNode root;

        /// <summary>
        /// Constructor! 
        /// All we need to do here is set the root to null and the size to 0
        /// </summary>
        public IntegerBST()
        {
            size = 0;
            root = null;
        }


        /// <summary>
        /// Add a new Node to the list.
        /// </summary>
        public void Add(int newvalue)
        {
            bool goneLeft = false;
            IntegerNode curr = null;
            IntegerNode prev = null;

            if (root == null)
            {
                root = new IntegerNode(newvalue);
                Console.WriteLine("Added Root with a Value of " + newvalue);
            }
            else
            {
                nodeNumber++;
				curr = root;
                do
                {
                    prev = curr;
                    if (curr.NodeContent >=  newvalue)
                    {
                        goneLeft = true;
                        curr = curr.Left;
                    }
                    else
                    {
                        goneLeft = false;
                        curr = curr.Right;
                    }
                } while (curr != null);

                if (goneLeft == true)
                {
                    prev.Left = new IntegerNode(newvalue);
					Console.WriteLine("Added Node number " + nodeNumber + "(Value " + newvalue + ")" + " To the Left");
				}
                else
                {
                    prev.Right = new IntegerNode(newvalue);
					Console.WriteLine("Added Node number " + nodeNumber + "(Value " + newvalue + ")" + " To the Right");
				}
            }
        }
		
		public int RemoveMax(ref IntegerNode startingPoint)
		{
            int valFound;
			if (startingPoint.Right == null)
			{
                valFound = startingPoint.NodeContent;
                startingPoint = null;
				Console.WriteLine("Found and removed the max value: " + valFound);
				return valFound;
			}
			else
			{
				Console.WriteLine("Didnt find the max value yet, recursing...");
                IntegerNode thisOne = startingPoint.Right;
                return RemoveMax(ref thisOne);
            }
		}

        public int RemoveMin(ref IntegerNode startingPoint)
		{
            int valFound;
			if (startingPoint.Left == null)
			{
                valFound = startingPoint.NodeContent;
                startingPoint = null;
                Console.WriteLine("Found and removed the min value: " + valFound);
                return valFound;
            }
            else
            {
                Console.WriteLine("Didnt find the min value yet, recursing...");
                IntegerNode thisOne = startingPoint.Right;
                return RemoveMin(ref thisOne);
            }
        }

        public bool Delete(int value)
		{
            IntegerNode curr, parent;
            bool currentIsLeftChild;
			curr = root;
            parent = root;

			if (root == null)
			{
                return false;
			}
			else if (root.NodeContent == value)
			{
                if (root.Left != null)
                {
                    IntegerNode thisOne = root.Left;
                    root.NodeContent = RemoveMax(ref thisOne);
                }
                else if (root.Right != null)
                {
                    IntegerNode thisOne = root.Right;
                    root.NodeContent = RemoveMax(ref thisOne);
                }
                else
                {
                    root = null;
                }
                size--;
                return true;
            }
			else
			{
				do
				{
                    parent = curr;
					if (value < curr.NodeContent)
					{
                        curr = curr.Left;
						currentIsLeftChild = true;
					}
					else
					{
						curr = curr.Right;
						currentIsLeftChild = false;
					}
					if (curr == null)
					{
                        return false;
					}
				} while (curr.NodeContent != value);

                if (curr.Left != null)
                {
					IntegerNode thisOne = curr.Left;
					curr.NodeContent = RemoveMax(ref thisOne);
                }
                else if (curr.Right != null)
				{
                    IntegerNode thisOne = curr.Right;
                    curr.NodeContent = RemoveMax(ref thisOne);
                }
				else
				{
					if (currentIsLeftChild)
					{
                        parent.Left = null;
					}
					else
					{
                        parent.Right = null;
					}
				}
                size--;
				return true;
			}
		}

		public void InOrderTraversal(IntegerNode startingPoint)
		{
			if (startingPoint.Left != null)
			{
                InOrderTraversal(startingPoint.Left);
			}
            Console.WriteLine(startingPoint.NodeContent);
            if (startingPoint.Right != null)
			{
                InOrderTraversal(startingPoint.Right);
            }
        }
	}
}

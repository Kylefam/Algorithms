using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BTree
{
    class Program
    {
        static void Main(string[] args)
        {
            IntegerBST BST = new IntegerBST();

            BST.Add(10);
            BST.Add(5);
            BST.Add(20);
            BST.Add(15);
            BST.Add(15);
            BST.Add(1);
            BST.Add(7);

            // With this data you should end up with a tree that looks like this:
            //
            //                               10
            //                               |
            //                /------------------------------\
            //                5                              20
            //                |                              |
            //         /-------------\               /--------
            //         1             7              15
            //                                      |
            //                                      15

            BST.InOrderTraversal(BST.root);
            Console.ReadLine();
        }
    }
}

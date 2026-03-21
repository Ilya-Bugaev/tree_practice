cmake_minimum_required(VERSION 3.25)
project(BST C)


add_library(bst bst.c)
add_library(stack stack.c)
add_library(iterator iterator.c)
add_library(statistic statistic.c)
add_library(inorder inorder.c)
add_library(bstIsValid checkBst.c)


add_executable(executable main.c)


target_link_libraries(executable PRIVATE bst stack iterator statistic inorder bstIsValid)
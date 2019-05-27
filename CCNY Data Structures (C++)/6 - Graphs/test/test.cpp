#include "hw6q1.h"
#include "hw6q2.h"
#include "gtest/gtest.h"

TEST(matrix, constructor) {
	graphM<char> g;

	EXPECT_EQ(0, g.numVertices());
	EXPECT_EQ(0, g.numEdges());
}

TEST(matrix, addVertex) {
	graphM<char> g;

	g.addVertex('a');

	EXPECT_EQ(1, g.numVertices());
	EXPECT_EQ(0, g.numEdges());
}

TEST(matrix, addEdge1) {
	graphM<char> g;

	g.addVertex('a');
	g.addVertex('b');

	g.addEdge(g.index('a'), g.index('b'), 1);


	EXPECT_EQ(2, g.numVertices());
	EXPECT_EQ(1, g.numEdges());
	EXPECT_EQ(true , g.isEdge(g.index('a'), g.index('b')));
	EXPECT_EQ(false, g.isEdge(g.index('b'), g.index('a')));
}

TEST(matrix, addEdge2) {
	graphM<char> g;

	g.addVertex('a');
	g.addVertex('b');

	g.addEdge(g.index('a'), g.index('b'), 1);
	g.addEdge(g.index('b'), g.index('a'), 1);

	EXPECT_EQ(2, g.numVertices());
	EXPECT_EQ(2, g.numEdges());
	EXPECT_EQ(true, g.isEdge(g.index('a'), g.index('b')));
	EXPECT_EQ(true, g.isEdge(g.index('b'), g.index('a')));
}

TEST(matrix, addEdge3) {
	graphM<char> g;

	g.addVertex('a');
	g.addVertex('b');

	g.addEdge(g.index('a'), g.index('b'), 1);
	g.addEdge(g.index('a'), g.index('b'), 2);
	g.addEdge(g.index('b'), g.index('a'), 1);

	EXPECT_EQ(2, g.numVertices());
	EXPECT_EQ(2, g.numEdges());
	EXPECT_EQ(true, g.isEdge(g.index('a'), g.index('b')));
	EXPECT_EQ(true, g.isEdge(g.index('b'), g.index('a')));
}

TEST(matrix, removeEdge1) {
	graphM<char> g;

	g.addVertex('a');
	g.addVertex('b');

	g.addEdge(g.index('a'), g.index('b'), 1);
	g.addEdge(g.index('b'), g.index('a'), 1);

	EXPECT_EQ(2, g.numVertices());
	EXPECT_EQ(2, g.numEdges());
	EXPECT_EQ(true, g.isEdge(g.index('a'), g.index('b')));
	EXPECT_EQ(true, g.isEdge(g.index('b'), g.index('a')));

	g.removeEdge(g.index('a'), g.index('b'));

	EXPECT_EQ(2, g.numVertices());
	EXPECT_EQ(1, g.numEdges());
	EXPECT_EQ(false, g.isEdge(g.index('a'), g.index('b')));
	EXPECT_EQ(true, g.isEdge(g.index('b'), g.index('a')));
}

TEST(matrix, removeEdge2) {
	graphM<char> g;

	g.addVertex('a');
	g.addVertex('b');

	g.addEdge(g.index('a'), g.index('b'), 1);
	g.addEdge(g.index('b'), g.index('a'), 1);

	EXPECT_EQ(2, g.numVertices());
	EXPECT_EQ(2, g.numEdges());
	EXPECT_EQ(true, g.isEdge(g.index('a'), g.index('b')));
	EXPECT_EQ(true, g.isEdge(g.index('b'), g.index('a')));

	g.removeEdge(g.index('a'), g.index('b'));
	g.removeEdge(g.index('a'), g.index('b'));

	EXPECT_EQ(2, g.numVertices());
	EXPECT_EQ(1, g.numEdges());
	EXPECT_EQ(false, g.isEdge(g.index('a'), g.index('b')));
	EXPECT_EQ(true, g.isEdge(g.index('b'), g.index('a')));
}

TEST(matrix, neighbors) {
	graphM<char> g;

	g.addVertex('a');
	g.addVertex('b');
	g.addVertex('c');
	g.addVertex('d');
	g.addVertex('e');

	g.addEdge(g.index('a'), g.index('b'), 1);
	g.addEdge(g.index('b'), g.index('a'), 1);
	g.addEdge(g.index('a'), g.index('e'), 1);
	g.addEdge(g.index('e'), g.index('a'), 1);
	g.addEdge(g.index('b'), g.index('c'), 1);
	g.addEdge(g.index('c'), g.index('b'), 1);
	g.addEdge(g.index('b'), g.index('d'), 1);
	g.addEdge(g.index('d'), g.index('b'), 1);
	g.addEdge(g.index('b'), g.index('e'), 1);
	g.addEdge(g.index('e'), g.index('b'), 1);
	g.addEdge(g.index('c'), g.index('d'), 1);
	g.addEdge(g.index('d'), g.index('c'), 1);
	g.addEdge(g.index('d'), g.index('e'), 1);
	g.addEdge(g.index('e'), g.index('d'), 1);
	
	EXPECT_EQ(5, g.numVertices());
	EXPECT_EQ(14, g.numEdges());

	// Test yourself
}

TEST(list, constructor) {
	graphL<char> g;

	EXPECT_EQ(0, g.numVertices());
	EXPECT_EQ(0, g.numEdges());
}

TEST(list, addVertex) {
	graphL<char> g;

	g.addVertex('a');

	EXPECT_EQ(1, g.numVertices());
	EXPECT_EQ(0, g.numEdges());
}

TEST(list, addEdge1) {
	graphL<char> g;

	g.addVertex('a');
	g.addVertex('b');

	g.addEdge(g.index('a'), g.index('b'), 1);


	EXPECT_EQ(2, g.numVertices());
	EXPECT_EQ(1, g.numEdges());
	EXPECT_EQ(true , g.isEdge(g.index('a'), g.index('b')));
	EXPECT_EQ(false, g.isEdge(g.index('b'), g.index('a')));
}

TEST(list, addEdge2) {
	graphL<char> g;

	g.addVertex('a');
	g.addVertex('b');

	g.addEdge(g.index('a'), g.index('b'), 1);
	g.addEdge(g.index('b'), g.index('a'), 1);

	EXPECT_EQ(2, g.numVertices());
	EXPECT_EQ(2, g.numEdges());
	EXPECT_EQ(true, g.isEdge(g.index('a'), g.index('b')));
	EXPECT_EQ(true, g.isEdge(g.index('b'), g.index('a')));
}

TEST(list, addEdge3) {
	graphL<char> g;

	g.addVertex('a');
	g.addVertex('b');

	g.addEdge(g.index('a'), g.index('b'), 1);
	g.addEdge(g.index('a'), g.index('b'), 2);
	g.addEdge(g.index('b'), g.index('a'), 1);

	EXPECT_EQ(2, g.numVertices());
	EXPECT_EQ(2, g.numEdges());
	EXPECT_EQ(true, g.isEdge(g.index('a'), g.index('b')));
	EXPECT_EQ(true, g.isEdge(g.index('b'), g.index('a')));
}

TEST(list, removeEdge1) {
	graphL<char> g;

	g.addVertex('a');
	g.addVertex('b');

	g.addEdge(g.index('a'), g.index('b'), 1);
	g.addEdge(g.index('b'), g.index('a'), 1);

	EXPECT_EQ(2, g.numVertices());
	EXPECT_EQ(2, g.numEdges());
	EXPECT_EQ(true, g.isEdge(g.index('a'), g.index('b')));
	EXPECT_EQ(true, g.isEdge(g.index('b'), g.index('a')));

	g.removeEdge(g.index('a'), g.index('b'));

	EXPECT_EQ(2, g.numVertices());
	EXPECT_EQ(1, g.numEdges());
	EXPECT_EQ(false, g.isEdge(g.index('a'), g.index('b')));
	EXPECT_EQ(true, g.isEdge(g.index('b'), g.index('a')));
}

TEST(list, removeEdge2) {
	graphL<char> g;

	g.addVertex('a');
	g.addVertex('b');

	g.addEdge(g.index('a'), g.index('b'), 1);
	g.addEdge(g.index('b'), g.index('a'), 1);

	EXPECT_EQ(2, g.numVertices());
	EXPECT_EQ(2, g.numEdges());
	EXPECT_EQ(true, g.isEdge(g.index('a'), g.index('b')));
	EXPECT_EQ(true, g.isEdge(g.index('b'), g.index('a')));

	g.removeEdge(g.index('a'), g.index('b'));
	g.removeEdge(g.index('a'), g.index('b'));

	EXPECT_EQ(2, g.numVertices());
	EXPECT_EQ(1, g.numEdges());
	EXPECT_EQ(false, g.isEdge(g.index('a'), g.index('b')));
	EXPECT_EQ(true, g.isEdge(g.index('b'), g.index('a')));
}

TEST(list, neighbors) {
	graphL<char> g;

	g.addVertex('a');
	g.addVertex('b');
	g.addVertex('c');
	g.addVertex('d');
	g.addVertex('e');

	g.addEdge(g.index('a'), g.index('b'), 1);
	g.addEdge(g.index('b'), g.index('a'), 1);
	g.addEdge(g.index('a'), g.index('e'), 1);
	g.addEdge(g.index('e'), g.index('a'), 1);
	g.addEdge(g.index('b'), g.index('c'), 1);
	g.addEdge(g.index('c'), g.index('b'), 1);
	g.addEdge(g.index('b'), g.index('d'), 1);
	g.addEdge(g.index('d'), g.index('b'), 1);
	g.addEdge(g.index('b'), g.index('e'), 1);
	g.addEdge(g.index('e'), g.index('b'), 1);
	g.addEdge(g.index('c'), g.index('d'), 1);
	g.addEdge(g.index('d'), g.index('c'), 1);
	g.addEdge(g.index('d'), g.index('e'), 1);
	g.addEdge(g.index('e'), g.index('d'), 1);
	
	EXPECT_EQ(5, g.numVertices());
	EXPECT_EQ(14, g.numEdges());

	// Test yourself
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
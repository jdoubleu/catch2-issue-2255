#include <vector>
#include <string>
#include <algorithm>

#include <catch2/catch.hpp>

namespace user_code
{

template<typename index_type, typename value_type>
struct Node
{
    index_type index;
    value_type value;

    Node(index_type index_, value_type value_)
        : index{index_}, value{std::move(value_)}
    {
    }

    bool operator<(const Node& other) const
    {
        return index < other.index;
    }
};

template<typename index_type, typename value_type>
struct Strict_node
{
    index_type index;
    value_type value;

    Strict_node(index_type index_, value_type value_)
        : index{index_}, value{std::move(value_)}
    {
    }

    bool operator<(const Strict_node& other) const
    {
        return index < other.index
            && value == other.value;
    }
};

template<typename value_type, template<typename, typename> typename node_type>
struct Algorithm
{
    using node = node_type<size_t, value_type>;
    std::vector<node> nodes;
    size_t current_index{};

    void insert(const value_type& value)
    {
        nodes.emplace_back(current_index++, value);
    }

    [[nodiscard]] bool is_sorted() const
    {
        return nodes.back().index == current_index - 1;
    }

    void sort()
    {
        std::sort(nodes.begin(), nodes.end());
    }
};

/*
TEMPLATE_TEST_CASE("what I want to do", "", Node, Strict_node)
{
    Algorithm<std::string, TestType> algo{};
    algo.insert("Hello");
    algo.insert("Test");
    algo.insert("World");

    algo.sort();
    REQUIRE(algo.is_sorted());
}
*/

/*
TEMPLATE_TEST_CASE_SIG("what I still cannot do", "",
    ((template<typename,typename> typename node_type), node_type),
    Node, Strict_node)
{
    Algorithm<std::string, node_type> algo{};
    algo.insert("Hello");
    algo.insert("Test");
    algo.insert("World");

    algo.sort();
    REQUIRE(algo.is_sorted());
}
*/

TEST_CASE("what I have to do")
{
    SECTION("variation 1")
    {
        Algorithm<std::string, Node> algo{};
        algo.insert("Hello");
        algo.insert("Test");
        algo.insert("World");

        algo.sort();
        REQUIRE(algo.is_sorted());
    }

    SECTION("variation 2")
    {
        Algorithm<std::string, Strict_node> algo{};
        algo.insert("100 Strings");
        algo.insert("2 Strings");

        algo.sort();
        REQUIRE(algo.is_sorted());
    }
}

}



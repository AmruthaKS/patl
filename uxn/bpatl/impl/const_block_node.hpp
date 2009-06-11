#ifndef BPATL_IMPL_CONST_BLOCK_NODE_HPP
#define BPATL_IMPL_CONST_BLOCK_NODE_HPP

#include "node.hpp"

namespace uxn
{
namespace bpatl
{
namespace impl
{

/// ������� ����� ������ ������������ ���������� ��� ��������
/// ���� ����� ������ ���� const_node_type_ref � bpatl_cont's
/// node_type_ref � const_node_type_ref ������ �������� (node_type*) � (const node_type*)
/// public-��������� ����� ������ ������ ��������� � readonly-����������� node_generic
template <typename Node, typename Container>
class const_block_node_generic
{
    typedef const_block_node_generic<Node, Container> this_t;
    typedef Container cont_type;
    typedef cont_type::node_type node_type;

public:
    const this_t *operator->() const
    {
        return this;
    }

    /// return parent node
    const_node_type_ref get_parent(const cont_type *cont) const
    {
        return nod_->get_parent(cont, block_);
    }

    /// return node id relate to parent
    word_t get_parent_id() const
    {
        return nod_->get_parent_id();
    }

    /// return child node by id
    const_node_type_ref get_xlink(const cont_type *cont, word_t id) const
    {
        return nod_->get_xlink(cont, block_, id);
    }

    /// return tag of child node by id
    word_t get_xtag(word_t id) const
    {
        return nod_->get_xtag(id);
    }

    /// return the number of distinction bit
    word_t get_skip() const
    {
        return nod_->get_skip();
    }

    const node_block *get_block() const
    {
        return block_;
    }

    const node_type *get_node() const
    {
        return nod_;
    }

protected:
    // ��������� �� �������������� ����
    node_block *block_; // ����� ���������� � algorithm_generic::init
    // ��������� �� ���������� ������������ ���� � �������������� �����
    node_type *nod_;
};

} // namespace impl
} // namespace bpatl
} // namespace uxn

#endif

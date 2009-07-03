#ifndef BPATL_IMPL_EXTALGORITHM_HPP
#define BPATL_IMPL_EXTALGORITHM_HPP

#include "node_block.hpp"

namespace uxn
{
namespace bpatl
{
namespace impl
{

template <typename Container>
class extalgorithm_generic
{
    typedef Container cont_type;
    typedef typename cont_type::node_block node_block;
    typedef typename node_block::outref outref_t;
    typedef typename cont_type::coralgorithm coralgorithm; 

public:
    typedef cont_type::coralgorithm exploit_t; // avatar of external_algorithm
    typedef exploit_t const_exploit_t;

    std::auto_ptr<const_exploit_t> exploit() const
    {
        // ��� ������ ����������� � ���� ���� � ����� ��� ������?
        // ������ �����, external_algorithm, ������ ��� �� �� ����� ��������� ���� ����
        // � �����������/��������� ����� ����� ��� ��������� �� �����
        return std::auto_ptr<const_exploit_t>(
            new const_exploit_t(this, ));
    }

    // ��� ������� ����� ���������� �� ���������� �� ������ ������������ ���������,
    // �� � �������� ������� ������� ���� � ���������� ����� dirty
    std::auto_ptr<exploit_t> exploit()
    {
        return std::auto_ptr<exploit_t>(
            new exploit_t(this, ));
    }

    // ���� ����� �������� ContainerProvider'�� ��� algorithm_generic
    const cont_type *cont() const
    {
        return cont_;
    }
    cont_type *cont()
    {
        return cont_;
    }

    void release_provider(const_exploit_t *cor)
    {
        // TODO ������������� ��������� cor � ��������� this->outref_
        // node_block ��� ��������, ��� �� ��� � node_type*
        // ������� �� ����� ����������� �� ���� ���������� �������� outref
        // ���� ����� �������� block_cache
        const_node_type_ref q(cor->get_q());
        const node_block *block = q.get_block();
        outref_ = cont_->get_bid_type_by_block(block); // ��� ������� ������� �� block_cache ����� cont
        outref_.set_offsetid(block->get_offset(q.get_node()), cor->get_qid());
    }

private:
    cont_type *cont_;
    outref_t outref_;
};

} // namespace impl
} // namespace bpatl
} // namespace uxn

#endif

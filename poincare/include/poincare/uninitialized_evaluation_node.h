#ifndef POINCARE_UNINITIALIZED_EVALUATION_NODE_H
#define POINCARE_UNINITIALIZED_EVALUATION_NODE_H

#include <poincare/evaluation.h>
#include <poincare/exception_evaluation_node.h>
#include <stdio.h>

namespace Poincare {

/* All UninitializedExpressions should be caught so its node methods are
 * asserted false. */

template<typename T>
class UninitializedEvaluationNode : public ExceptionEvaluationNode<EvaluationNode, T> {
public:
  // TreeNode
  bool isUninitialized() const override { return true; }
  TreeNode * failedAllocationStaticNode() override { /*TODO*/ assert(false); return nullptr; /* Or call parent method ?*/ }
  size_t size() const override { return sizeof(UninitializedEvaluationNode); }
#if POINCARE_TREE_LOG
  virtual void logNodeName(std::ostream & stream) const override {
    stream << "UninitializedEvaluation";
  }
#endif
};

template<typename T>
class UninitializedEvaluation : public Expression {
public:
  UninitializedEvaluation() : Expression(UninitializedEvaluationStaticNode()) {}
private:
  static UninitializedEvaluationNode<T> * UninitializedEvaluationStaticNode();
};

}

#endif
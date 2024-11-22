#include "proof_logger.h"

std::size_t ProofLogger::log(const LogEntity &theorem) {
    theorems.push_back(theorem);
    return theorems.size();
}

void ProofLogger::markAsUsed(const std::size_t id) {
    if (isUsed(id))
        return;
    used_theorems.insert(id);
    auto theorem = getTheorem(id);
    if (theorem.substitution_initial_expression != std::nullopt)
        markAsUsed(*theorem.substitution_initial_expression);
    if (theorem.inference_rule == std::nullopt || theorem.inference_rule_arguments == std::nullopt)
        return;
    for (const auto &theorem_id: *theorem.inference_rule_arguments)
        markAsUsed(theorem_id);
}

bool ProofLogger::isUsed(const std::size_t id) const {
    return used_theorems.find(id) != used_theorems.end();
}

const LogEntity &ProofLogger::getTheorem(const std::size_t id) const {
    return theorems[id - 1];
}

void ProofLogger::printTheorem(const std::size_t id, std::ostream &output_stream) const {
    output_stream << std::to_string(id) << ". " << getTheorem(id).toString() << std::endl;
}

void ProofLogger::printUsedTheorems(std::ostream &output_stream) const {
    for (const auto &id: used_theorems) {
        printTheorem(id, output_stream);
    }
}

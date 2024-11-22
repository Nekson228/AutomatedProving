#ifndef PROOF_LOGGER_H
#define PROOF_LOGGER_H

#include <set>
#include <vector>
#include <ostream>

#include "proof/proof_logger/log_entity.h"

class ProofLogger {
    std::vector<LogEntity> theorems;
    std::set<std::size_t> used_theorems;

public:
    std::size_t log(const LogEntity &theorem);

    void markAsUsed(std::size_t id);

    [[nodiscard]] bool isUsed(std::size_t id) const;

    [[nodiscard]] const LogEntity &getTheorem(std::size_t id) const;

    void printTheorem(std::size_t id, std::ostream &output_stream) const;

    void printUsedTheorems(std::ostream &output_stream) const;
};


#endif //PROOF_LOGGER_H

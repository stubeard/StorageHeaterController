#ifndef __MODEL_TEST_H__
#define __MODEL_TEST_H__

#include "IModelListener.h"
#include "IModel.h"
#include <vector>
#include <string>

namespace StorageHeaterControl
{
    namespace Test
    {
        /** \brief Class for testing Model implementation
         *
         */

        class ModelTest : public IModelListener
        {
            public:
                ModelTest( IModel &model );
                virtual ~ModelTest();
                virtual void modelChanged();
                void encodeTestString( std::string test );
            private:
                IModel &m_model;
                std::vector<bool> m_test;
                std::vector<bool> m_result;
        };
    }
}

#endif // __MODEL_TEST_H__

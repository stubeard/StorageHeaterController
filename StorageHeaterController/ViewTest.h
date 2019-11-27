#ifndef __VIEW_TEST_H__
#define __VIEW_TEST_H__

#include "IViewListener.h"
#include "IView.h"

namespace StorageHeaterControl
{
    /** \brief Test Classes for the StorageHeaterControl application.
     *
     */
    namespace Test
    {
        /** \brief Class for testing View implementation
         *
         */

        class ViewTest : public IViewListener
        {
            public:
                ViewTest( IView &view );
                virtual ~ViewTest();
                virtual void viewChanged();

            private:
                IView &m_view;
        };
    }
}
#endif // __VIEW_TEST_H__

# manage-employee-program

## Chương trình quản lý nhân viên gồm các yêu cầu sau:
    + Thông tin nhân viên:
        - id: Mã số nhân viên
        - name: Họ và tên nhân viên
        - salary_base: Hệ số lương cơ bản
        - working_days: Số ngày làm việc trong tháng
        - department_id: Mã bộ phận
        - working_performance: Hệ số hiệu quả
        - bonus: Thưởng
        - late_comming_days: Số ngày đi muộn
    
    + Thông tin bộ phận:
        - id: Mã bộ phận
        - bonus_salary: Thưởng bộ phận
        
    + Trừ đi muộn:
        - Đi trễ <= 3 ngày/tháng: 10000 VNĐ
        - Đi trễ  > 3 ngày/tháng: 20000 VNĐ
        - phạt đi muộn = late_comming_days * tiền phạt đi trễ
        
    + Tính lương cho nhân viên:
        - tổng thu nhập chưa thưởng = (salary_base * working_days) * working_performance
        - tổng thu nhập  = tổng thu nhập chưa thưởng + bonus + thưởng bộ phận - phạt đi muộn
        - Nhân viên sẽ cần trích ra 10.5% thu nhập để đóng bảo hiểm:
            tổng thu nhập chưa thuế = tổng thu nhập * 89.5 %
        - Khoản thuế cần nộp:
            > Nếu lương của nhân viên nằm trong nửa khoảng 0 VNĐ đến 11,000,00 VNĐ thì sẽ cần đóng thuế = 0% lương.
            > Nếu lương của nhân viên nằm trong nửa khoảng 11,000,00 VNĐ đến 16,000,00 VNĐ thì sẽ cần đóng thuế = 5% lương.
            > Nếu lương của nhân viên trên 16,000,00 VNĐ thì sẽ cần đóng thuế = 10% lương.
        - lương thực nhận = tổng thu nhập chưa thuế - khoản thuế cần nộp
        
    + Tạo menu khi khởi động chương trình:
        1. Hiển thị danh sách nhân viên.
        2. Hiển thị danh sách bộ phận.
        3. Thêm nhân viên mới.
        4. Xóa nhân viên theo ID.
        5. Xóa bộ phân theo ID.
        6. Hiển thị bảng lương.
        7. Thoát.
        Mời bạn nhập chức năng mong muốn:
        >1. Hiển thị danh sách nhân viên.
            ----
            Mã số: NV001
            Mã bộ phận: SALE001
            Họ và tên: Nguyễn Văn A
            Hệ số lương: 200,000 (VND)
            Số ngày làm việc: 26 (ngày)
            Hệ số hiệu quả: 1
            Thưởng: 500,000 (VND)
            Số ngày đi muộn: 2
            ----
            Lưu ý: Hiển thị ra màn hình theo hệ số hiệu quả giảm dần.
        >2. Hiển thị danh sách bộ phận.
            ----
            Mã bộ phận: SALE01
            Thưởng bộ phận: 500,000 (VND)
            ----
        >3. Thêm nhân viên mới.
            ----
            Thêm nhân viên mới ...
            Nhập mã số: 'NV002'
            Nhập mã bộ phận: 'SALE002'
            Nhập họ và tên: 'Nguyen Van B'
            Nhập hệ sô lương: '300000'
            Nhập số ngày làm việc: '25'
            Nhập hệ số hiệu quả: '0.8'
            Nhập thưởng: '0'
            Nhập số ngày đi muộn: '0'
            Đã thêm nhân viên mới ...
            ----
        >4. Xóa nhân viên theo ID.
            ----
            Nhập mã nhân viên muốn xóa: 'NV001'
            Đã xóa thành công
            ----
        >5. Xóa bộ phân theo ID.
            Tương tự với chức năng "Xóa nhân viên theo ID" nhưng là xóa bộ phận trên hệ thống.
            Lưu ý: Nếu đang có nhân viên trong bộ phận muốn xóa, hãy hiển thị ra lỗi "Bạn không thể xóa bộ phận đang có nhân viên".
        >6. Hiển thị bảng lương.
            ----
            Mã số: NV001
            Thu nhập thực nhận: 4,961,880 (VND)
            ----
        >7. Thoát.
            Kết thúc chương trình

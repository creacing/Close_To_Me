<template>
  <nav class="pagination">
    <span class="prev" @click="prePage" v-show="curPageList[0] !==1">
      <i class="ic i-angle-left" aria-label="上一页"></i>
    </span>

    <span
      class="page-number"
      @click="toPage(index)"
      v-for="index in curPageList"
      :key="index"
      :class="currentIndex === index?'current':''"
    >{{index}}</span>

    <span class="next" @click="nextPage" v-if="curPageList[curPageList.length-1] !==pageNum">
      <i class="ic i-angle-right" aria-label="下一页"></i>
    </span>
  </nav>
</template>
<script setup>
import { defineProps, toRefs, defineEmits, ref } from 'vue'

const curPageList = ref([])
const currentIndex = ref(1)

const props = defineProps({
  pageNum: {
    type: Number,
    default: 0
  }
})

const emits = defineEmits(['getCurIndex'])
const { pageNum } = toRefs(props)

const initCurPageList = () => {
  if (pageNum.value > 5) {
    curPageList.value = [1, 2, 3, 4, 5]
  } else {
    for (let i = 0; i < pageNum.value; i++) {
      curPageList.value.push(i)
    }
  }
}

initCurPageList()

const nextPage = () => {
  const last = curPageList.value[4]
  const temp = []
  if (last + 5 > pageNum.value) {

    for (let i = last + 1; i <= pageNum.value; i++) {
      temp.push(i)
    }
    curPageList.value = temp
  } else {

    curPageList.value = [last + 1, last + 2, last + 3, last + 4, last + 5]
  }
}
const prePage = () => {
  const first = curPageList.value[0]
  const temp = []

  curPageList.value = [first - 5, first - 4, first - 3, first - 2, first - 1]
}
const toPage = (pageIndex) => {
  currentIndex.value = pageIndex
  emits("getCurIndex", pageIndex);
}
</script>

<style scoped lang='scss'>
.pagination {
  width: 100%;
  padding: 1.25rem 3.125rem;
  text-align: center;
  display: inline-block;
  color: var(--grey-5);
  .next:hover,
  .page-number.current,
  .page-number:hover,
  .prev:hover {
    color: var(--grey-0);
    background-image: linear-gradient(
      to right,
      var(--color-pink) 0,
      var(--color-orange) 100%
    );
    opacity: 0.9;
    border-radius: 0.625rem;
  }

  .next,
  .page-number,
  .prev,
  .space {
    display: inline-block;
    margin: 0 0.5rem;
    padding: 0 0.75rem;
    position: relative;
    border-radius: 0.3125rem;
  }

  @media (max-width: 767px) {
    .next,
    .page-number,
    .prev,
    .space {
      margin: 0 0.3125rem;
    }
    .page-number {
      padding: 0 0.375rem;
    }
  }

  .next,
  .page-number,
  .prev {
    transition: all 0.2s ease-in-out 0s;
  }

  .space {
    margin: 0;
    padding: 0;
  }

  .prev {
    margin-left: 0;
  }

  .next {
    margin-right: 0;
  }

  .page-number.current:hover {
    box-shadow: 0 0 0.3125rem var(--primary-color);
  }
}

@media (max-width: 767px) {
  .pagination {
    padding: 1.25rem 0.125rem;
  }
}
</style>
